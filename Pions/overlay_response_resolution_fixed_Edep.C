// //int point_col[4] = {kBlue, kRed, kBlack, kMagenta};
// int point_col[4] = {kRed, kBlack, kBlue, kMagenta};

// //int point_style[3] = {kFullCircle,kOpenSquare,kFullTriangleUp};
// int point_style[3] = {kOpenSquare,kFullCircle,kFullTriangleUp};
//bool save_ = true;
//bool doResoFit = false;
const int n_pl = 4;
TString pls[4] = {"FTFP_BERT_EMN","QGSP_FTFP_BERT_EMN","FTFP_BERT_EMM","QGSP_BERT",};
//TString chi2methods[4] = {"method a","method b","method c","method d",};
TString chi2methods[] = {"Energy dep weights","Fixed weights","Fixed weights"};
//TString chi2methods[4] = {"Data v16v8","sim_v44","sim_v46_patchMIP"};

float point_size[5] = {1.2,1.2,1.2,1,1};
//int point_style[n_pl+1] = {1,1,1,1,1};
//int point_style[5] = {kFullCircle,kOpenSquare,kFullTriangleUp,kFullTriangleDown,kOpenTriangleUp};
int point_style[5] = {kFullCircle,kFullCircle,kFullTriangleUp,kFullTriangleDown,kOpenTriangleUp};

int point_col[5] = {kBlue, kRed, kBlack, kBlue, kRed};
double energy_list [] = {20.0,50.0,80.0,100.0,120.0,200.0,250.0,300.0};
struct graph_points {
  double x1[8];
  double x2[8];
  double y1[8];
  double y2[8];
};


float calculate_error(float x, float dx, float y, float dy) {
  return (((x/y)*(TMath::Sqrt((dx/x)*(dx/x) + (dy/y)*(dy/y)))));

}


void overlay_response(const char* shower="", bool save_ = false){
  char* y_tit = new char[500];
  sprintf(y_tit,"Response [#mu_{gaus}/E_{beam}]");
  char* canvas_savename = new char[1000];
  char* tex_method = new char[500];
  float y_range[2];
  float ratio_range[2];
  char* method = new char[100];
  sprintf(method,"gaus");
  if(!strcmp(shower,"EE")) {
    sprintf(tex_method,"Showering in CE-E");
    y_range[0] = 0.5; y_range[1] = 1.5;
    ratio_range[0] = 0.9; ratio_range[1] = 1.15;
    sprintf(canvas_savename,"response_fixed_Edep_showeringInEE");

  }
  else if(!strcmp(shower,"FH")) {
    sprintf(tex_method,"MIPs in CE-E");
    y_range[0] = 0.5; y_range[1] = 1.5;
    ratio_range[0] = 0.9; ratio_range[1] = 1.15;
    sprintf(canvas_savename,"response_fixed_Edep_MIPsInEE");
  }
  else if(!strcmp(shower,"all")) {
    sprintf(tex_method,"Inclusive");
    y_range[0] = 0.5; y_range[1] = 1.5;
    ratio_range[0] = 0.9; ratio_range[1] = 1.15;
    sprintf(canvas_savename,"response_fixed_Edep_inclusive");
  }
  else {
    cout<<"method: [fixed or Ebeam]"<<endl;
    return;
  }


  //For WebPage
 
  TCanvas *mycanvas = new TCanvas("mycanvas","mycanvas",800,500);
  mycanvas->SetRightMargin(0.009);
  // auto *p2 = new TPad("p2","p2",0.,0.0,1.,0.32); p2->Draw();
  // p2->SetTopMargin(0.001);
  // p2->SetBottomMargin(0.3);
  // //p2->SetBottomMargin(0.15);
  // p2->SetRightMargin(0.009);
  // p2->SetLeftMargin(0.11);
  // p2->SetGrid();

  // //auto *p1 = new TPad("p1","p1",0.,0.3,1.,1.);  p1->Draw();
  // auto *p1 = new TPad("p1","p1",0.,0.32,1.,1.);  p1->Draw();
  // //p1->SetTopMargin(0.05);
  // p1->SetBottomMargin(0.001);
  // p1->SetRightMargin(0.009);
  // p1->SetLeftMargin(0.11);
  // p1->cd();
  // p1->SetGrid();
 
  TLegend *legend = new TLegend(0.6,0.90,0.99,0.65);

  TLegendEntry* l1[4];// = legend->AddEntry(hist_data,hist_data->GetName(),"l");
  

  
  //legend->SetNColumns(2);
  vector<TString> legName;
  
  legName.push_back("Fixed weights");
  legName.push_back("E-dependent weight");
  
  

  // Instance of the graph
  // TGraphErrors *graph_chip[2];
  TGraphErrors *temp_graph;
  std::vector<TGraphErrors *> graph_response;

  char* temp_txt = new char[500];
  std::vector<TString>  txt_fileName;

  
  // sprintf(temp_txt,"./txt_files/response_resolution/data/response_data_chi2methodEbeam_%s_%s.txt",shower,method);
  // txt_fileName.push_back(temp_txt);
  // sprintf(temp_txt,"./txt_files/response_resolution/data/response_data_chi2methodfixed_%s_%s.txt",shower,method);
  // txt_fileName.push_back(temp_txt);
  
  sprintf(temp_txt,"./txt_files/response_resolution/data/response_data_chi2methodfixed_%s_gaus.txt",shower);
  txt_fileName.push_back(temp_txt);
  sprintf(temp_txt,"./txt_files/response_resolution/data/response_data_chi2methodEbeam_%s_gaus.txt",shower);
  txt_fileName.push_back(temp_txt);
  
  
  graph_points g_p[4];
  graph_points r_p[4];

  for(int i = 0; i < txt_fileName.size(); i++) {
    std::ifstream in(txt_fileName[i]);
    if(!in) {
      cout<<"Could not load file: "<<txt_fileName[i]<<endl;
      return;
    }
    int j = 0;
    double x1_,x2_,y1_,y2_;
    while(in>>x1_>>y1_>>x2_>>y2_) {
      g_p[i].x1[j] = x1_;
      g_p[i].x2[j] = x2_;
      g_p[i].y1[j] = y1_;
      g_p[i].y2[j] = y2_;
      if(i!=0) {
        r_p[i-1].x1[j] = x1_;
        r_p[i-1].x2[j] = x2_;
        r_p[i-1].y1[j] = y1_/g_p[0].y1[j];
        r_p[i-1].y2[j] = calculate_error(y1_,y2_,g_p[0].y1[j],g_p[0].y2[j]);
        //cout<<"Error: "<<r_p[i-1].y2[j]<<endl;
      }
      j++;
    }
  }


  for(int i = 0; i < txt_fileName.size(); i++) {
    //temp_graph = new TGraphErrors(txt_fileName[i].Data(),"%lg %lg %lg %lg %lg");
    temp_graph = new TGraphErrors(8, g_p[i].x1, g_p[i].y1, g_p[i].x2, g_p[i].y2);
    graph_response.push_back(temp_graph);
    
    
  }
  

  

  char *g_title = new char[100];

  for(int ii = 0; ii<txt_fileName.size(); ii++) {

    //graph_chip[ii]->SetTitle(g_name);
    graph_response[ii]->SetTitle(0);
    //graph_response[ii]->SetTitleX1(0.5);

    graph_response[ii]->SetMarkerStyle(point_style[ii]);
    graph_response[ii]->SetMarkerColor(point_col[ii]);
    graph_response[ii]->SetMarkerSize(point_size[ii]);
    graph_response[ii]->SetLineColor(point_col[ii]);

    graph_response[ii]->GetXaxis()->SetTitleSize(0.05);
    graph_response[ii]->GetXaxis()->SetLabelSize(0.05);
    graph_response[ii]->GetXaxis()->SetTitleOffset(0.8);

    graph_response[ii]->GetYaxis()->SetTitleSize(0.055);
    graph_response[ii]->GetYaxis()->SetLabelSize(0.05);
    
    graph_response[ii]->GetYaxis()->SetTitleOffset(0.8);

    graph_response[ii]->GetXaxis()->SetRangeUser(0.0,320.0);
    //graph_response[ii]->GetYaxis()->SetRangeUser(0.5,1.02);
    graph_response[ii]->GetYaxis()->SetRangeUser(y_range[0],y_range[1]);
    
    graph_response[ii]->GetXaxis()->SetTitle("Beam Energy [GeV]");
    
    //graph_response[ii]->GetYaxis()->SetTitle("<#mu>/E_{beam}");

    graph_response[ii]->GetYaxis()->SetTitle(y_tit);

    
  
    if (ii == 0)
      graph_response[ii]->Draw("APE");
    else
      graph_response[ii]->Draw("PE sames");

    //legend->AddEntry(graph_response[ii],legName[ii],"pe");
    l1[ii] = legend->AddEntry(graph_response[ii],legName[ii],"pe");
    l1[ii]->SetTextColor(graph_response[ii]->GetMarkerColor());
    //legend->AddEntry(graph_chip[ii],"YOLO","e");
    // TPaveText *pt = new TPaveText(.05,.1,.95,.8);
    // pt->AddText("Layer-1");
    // pt->Draw();
    mycanvas->Modified();

  }

  TLine *line = new TLine(0.0,1.0,320,1.0);
  line->SetLineStyle(2);
  line->SetLineWidth(2);
  line->SetLineColor(kBlack);
  line->Draw("SAME");
  legend->Draw();

  TLatex* textOnTop = new TLatex();
  textOnTop->SetTextSize(0.05);
  textOnTop->DrawLatexNDC(0.12,0.92,"CMS #it{#bf{Preliminary}}");
  textOnTop->DrawLatexNDC(0.6,0.92,"#bf{HGCAL OctTB @ H2, #pi^{-} beam}");

  // char* lat_text = new char[1000];
  // if(!strcmp(shower,"EE"))
  //   sprintf(lat_text,"#bf{Showering in CE-E}");
  // else if(!strcmp(shower,"FH"))
  //   sprintf(lat_text,"#bf{MIPs in CE-E}");
  // else {
  //   cout<<"Incorrect Input!!"<<endl;
  //   sprintf(lat_text,"Incorrect Input!!");
  //   return;
  // }

  textOnTop->SetTextSize(0.06);
  textOnTop->DrawLatexNDC(0.15,0.82,tex_method);
  
  sprintf(tex_method,"#bf{Gaussian fit}");
  textOnTop->SetTextSize(0.055);
  textOnTop->DrawLatexNDC(0.15,0.75,tex_method);
  

  gPad->SetTickx();
  gPad->SetTicky();
  // gPad->SetGridx();
  // gPad->SetGridy();



  ////////////////////////////////////////////////////
  ////////////////////////////////////////////////////
  ////////////////////////////////////////////////////
  // p2->cd();
  
  // std::vector<TGraphErrors *> ratio_response;
  
  // for(int i = 0; i < txt_fileName.size() - 1; i++) {
  //   temp_graph = new TGraphErrors(8, r_p[i].x1, r_p[i].y1, r_p[i].x2, r_p[i].y2);
  //   ratio_response.push_back(temp_graph);
    
  // }

  // for(int ii = 0; ii<txt_fileName.size() - 1; ii++) {

  //   //ratio_chip[ii]->SetTitle(g_name);
  //   ratio_response[ii]->SetTitle(0);
  //   //ratio_response[ii]->SetTitleX1(0.5);

  //   ratio_response[ii]->SetMarkerStyle(point_style[ii+1]);
  //   ratio_response[ii]->SetMarkerColor(point_col[ii+1]);
  //   ratio_response[ii]->SetLineColor(point_col[ii+1]);

  //   ratio_response[ii]->GetXaxis()->SetTitleSize(0.13);
  //   ratio_response[ii]->GetXaxis()->SetLabelSize(0.15);

    
  //   ratio_response[ii]->GetYaxis()->SetLabelSize(0.12);

  //   ratio_response[ii]->GetXaxis()->SetRangeUser(0.0,320.0);
  //   //ratio_response[ii]->GetYaxis()->SetRangeUser(0.99,1.02);
  //   //ratio_response[ii]->GetYaxis()->SetRangeUser(0.80,1.20);
  //   ratio_response[ii]->GetYaxis()->SetRangeUser(ratio_range[0],ratio_range[1]);
    
  //   ratio_response[ii]->GetXaxis()->SetTitle("Beam Energy [GeV]");
    
  //   //ratio_response[ii]->GetYaxis()->SetTitle("<#mu>/E_{beam}");

  //   //ratio_response[ii]->GetYaxis()->SetTitle("Point^{i}/Point^{1}");
  //   ratio_response[ii]->GetYaxis()->SetTitle("MC/Data");

  //   // ratio_response[ii]->GetXaxis()->SetTitleOffset(0.8);
  //   ratio_response[ii]->GetYaxis()->SetTitleSize(0.12);
  //   ratio_response[ii]->GetYaxis()->SetTitleOffset(0.4);


  //   if (ii == 0)
  //     ratio_response[ii]->Draw("APE");
  //   else
  //     ratio_response[ii]->Draw("PE sames");

   
  //   mycanvas->Modified();

  // }
  // TLine *line1 = new TLine(0.0,1.0,320,1.0);
  // line1->SetLineStyle(2);
  // line1->SetLineWidth(2);
  // line1->SetLineColor(kBlack);
  // line1->Draw("SAME");


  ////////////////////////////////////////////////////






  char *can_t = new char[1000];
  char *save_name = new char[1000];
  //sprintf(can_t,"./plots/response_and_resolution_plot/overlay_data_sim/response");
  sprintf(can_t,"./plots/response_resolution/");
  if(save_){
    sprintf(save_name,"%s/%s.png",can_t,canvas_savename);
    mycanvas->SaveAs(save_name);
    sprintf(save_name,"%s/%s.pdf",can_t,canvas_savename);
    mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.jpg",can_t);
    // mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.gif",can_t);
    // mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.root",can_t);
    // mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.C",can_t);
    // mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.pdf",can_t);
    // mycanvas->SaveAs(save_name);
  }
  
}





void overlay_resolution(bool doResoFit = false, const char* shower="", bool save_ = false){

  char* y_tit = new char[500];
  char* tex_method = new char[500];
  sprintf(y_tit,"Resolution [#sigma/#mu]");
  float yrange[2] = {0.05,0.45};
  char* canvas_savename = new char[1000];
  const char* method = "gaus";
  if(!strcmp(shower,"EE")) {
    sprintf(tex_method,"Showering in CE-E");
    sprintf(canvas_savename,"resolution_fixed_Edep_showeringInEE");
  }
  else if(!strcmp(shower,"FH")) {
    sprintf(tex_method,"MIPs in CE-E");
    sprintf(canvas_savename,"resolution_fixed_Edep_MIPsInEE");
  }
  else if(!strcmp(shower,"all")) {
    sprintf(tex_method,"Inclusive");
    sprintf(canvas_savename,"resolution_fixed_Edep_inclusive");
  }
  else {
    cout<<"method: [fixed or Ebeam]"<<endl;
    return;
  }
 
  //For WebPage
  
  //TCanvas *mycanvas = new TCanvas("mycanvas","mycanvas",600,350);
  char* canvas_name = new char[1000];
  sprintf(canvas_name,"resolution_%s_EE_FH_all",method);

  //TCanvas *mycanvas = new TCanvas("mycanvas","mycanvas",600,400);
  TCanvas *mycanvas = new TCanvas(canvas_name,canvas_name,800,500);
  
  mycanvas->SetRightMargin(0.009);
  mycanvas->SetLeftMargin(0.11);
  mycanvas->SetTopMargin(0.05);
  
  TLegend *legend;

  if(doResoFit) {
    //legend = new TLegend(0.60,0.945,0.99,0.20);
    legend = new TLegend(0.50,0.945,0.99,0.50);
    legend->SetNColumns(2);
    legend->SetBorderSize(0);
    legend->SetTextSize(0.04);
  }
  else {
    legend = new TLegend(0.65,0.94,0.99,0.6);
    legend->SetTextSize(0.045);
  }

  
   TLegendEntry* l1[4];
   TLegendEntry* l2[4];

  vector<TString> legName;
  legName.push_back("Fixed weights");
  legName.push_back("E-dependent weight");

  TGraphErrors *temp_graph;
  std::vector<TGraphErrors *> graph_resolution;

  char* temp_txt = new char[500];
  std::vector<TString>  txt_fileName;

  
  sprintf(temp_txt,"./txt_files/response_resolution/data/resolution_data_chi2methodfixed_%s_gaus.txt",shower);
  txt_fileName.push_back(temp_txt);
  sprintf(temp_txt,"./txt_files/response_resolution/data/resolution_data_chi2methodEbeam_%s_gaus.txt",shower);
  txt_fileName.push_back(temp_txt);

  
  for(int i = 0; i < txt_fileName.size(); i++) {
    temp_graph = new TGraphErrors(txt_fileName[i].Data(),"%lg %lg %lg %lg %lg");
    graph_resolution.push_back(temp_graph);
    
  }
  
 
  
  char *g_title = new char[100];
  
  TF1 *reso_fit[4];
 
  for(int ii = 0; ii < txt_fileName.size(); ii++) {

    //graph_resolution[ii]->SetTitle(g_name);
    graph_resolution[ii]->SetTitle(0);
    //graph_resolution[ii]->SetTitleX1(0.5);

    graph_resolution[ii]->SetMarkerStyle(point_style[ii]);
    graph_resolution[ii]->SetMarkerColor(point_col[ii]);
    //graph_resolution[ii]->SetMarkerSize(1.5);
    graph_resolution[ii]->SetMarkerSize(1.0);
    graph_resolution[ii]->SetLineColor(point_col[ii]);

    graph_resolution[ii]->GetXaxis()->SetTitleSize(0.05);
    graph_resolution[ii]->GetXaxis()->SetLabelSize(0.05);

    graph_resolution[ii]->GetYaxis()->SetTitleSize(0.05);
    graph_resolution[ii]->GetYaxis()->SetLabelSize(0.05);

    graph_resolution[ii]->GetXaxis()->SetRangeUser(0.0,320.0);
    
    //graph_resolution[ii]->GetYaxis()->SetRangeUser(0.05,0.90);
    // graph_resolution[ii]->GetYaxis()->SetRangeUser(0.02,1.20);
    graph_resolution[ii]->GetYaxis()->SetRangeUser(yrange[0],yrange[1]);
    graph_resolution[ii]->GetXaxis()->SetTitle("Beam Energy [GeV]");
    //graph_resolution[ii]->GetYaxis()->SetTitle("#sigma/#mu");
    graph_resolution[ii]->GetYaxis()->SetTitle(y_tit);

    graph_resolution[ii]->GetXaxis()->SetTitleOffset(0.8);
    graph_resolution[ii]->GetYaxis()->SetTitleOffset(1.1);

    gPad->SetTickx();
    gPad->SetTicky();
    // gPad->SetGridx();
    // gPad->SetGridy();

    

    if (ii == 0)
      graph_resolution[ii]->Draw("APE");
    else
      graph_resolution[ii]->Draw("PE sames");
    string legend_txt;
    if(doResoFit) {
        // reso_fit[ii] = new TF1("reso","sqrt([0]*[0]+[1]*[1]/x+[2]*[2]/(x*x) + [3]*[3]/sqrt(x))",20,300);
        // reso_fit[ii]->SetParameters(0.06,1.20,0.1,0.1);
        
        reso_fit[ii] = new TF1("reso","sqrt([0]*[0]+[1]*[1]/x+[2]*[2]/(x*x))",20,300);
        reso_fit[ii]->SetParameters(0.06,1.20,0.);
        
        reso_fit[ii]->SetLineColor(point_col[ii]);
        reso_fit[ii]->SetLineWidth(1);
        reso_fit[ii]->SetLineStyle(2);
        graph_resolution[ii]->Fit(reso_fit[ii],"","R",15,330);
    
        
        cout<<endl<<reso_fit[ii]->GetParameter(0)<<":"<<reso_fit[ii]->GetParameter(1)<<":"<<reso_fit[ii]->GetParameter(2)<<endl;

        char* fit_params = new char[2000];
        // sprintf(fit_params,"#splitline{S = (%0.1f #pm %0.1f)%% GeV^{0.5}}{C = (%0.1f #pm %0.1f)%%}",100*reso_fit[ii]->GetParameter(1),100*reso_fit[ii]->GetParError(1),100*reso_fit[ii]->GetParameter(0),100*reso_fit[ii]->GetParError(0));
        sprintf(fit_params,"#splitline{S = (%0.1f#pm %0.1f)%%}{C = (%0.1f#pm %0.1f)%%}",100*reso_fit[ii]->GetParameter(1),100*reso_fit[ii]->GetParError(1),100*reso_fit[ii]->GetParameter(0),100*reso_fit[ii]->GetParError(0));
        cout<<endl<<"S  = "<<100*reso_fit[ii]->GetParameter(1)<<"+/-"<<100*reso_fit[ii]->GetParError(1)
            << " , C = " <<100*reso_fit[ii]->GetParameter(0)<<"+/-"<<100*reso_fit[ii]->GetParError(0)<<endl;

        // param(0) is constant term
        // param(1) is stochastic term
        // param(2) is noise term



        // fres2 is stochastic term  (in %)
        // fres0.fres1 is constant terms (in %) (e.g. =>  8.2, fres0 = 8 & fres1 = 2) 

        int fres0 = (int)(reso_fit[ii]->GetParameter(0)*100.);
        int fres1 = (int)(10.*(reso_fit[ii]->GetParameter(0)*100.-fres0));
        int fres2 = (int)(reso_fit[ii]->GetParameter(1)*100.);
        cout<<fres0<<":"<<fres1<<":"<<fres2<<endl;
        cout<<"Eval at 100: "<<reso_fit[ii]->Eval(100)<<endl;
        // char text[100];
        // sprintf(text,"#sigma/E = %i%/#sqrt{E} + %i.%i%",fres2,fres0,fres1);
        TString text = "#sigma/E = ";
        text+=(int)fres2;
        text+="%/#sqrt{E} + ";
        text+=(int)fres0;
        text+=".";
        text+=(int)fres1;
         
        //legend_txt += text;
        legend_txt += (TString)fit_params;
    }
    l1[ii] = legend->AddEntry(graph_resolution[ii],legName[ii],"pe");
    l1[ii]->SetTextColor(graph_resolution[ii]->GetMarkerColor());
    if(doResoFit) {
        l2[ii] = legend->AddEntry(graph_resolution[ii],legend_txt.c_str(),"l");
        l2[ii]->SetTextColor(graph_resolution[ii]->GetMarkerColor());
    }
    
    mycanvas->Modified();

  }

  TLine *line = new TLine(0.0,1.0,320,1.0);
  line->SetLineStyle(2);
  line->SetLineWidth(2);
  line->SetLineColor(kRed);
  line->Draw("SAME");

  
  legend->Draw();

  char* lat_text = new char[1000];
  TLatex* textOnTop = new TLatex();
  textOnTop->SetTextSize(0.05);
  textOnTop->DrawLatexNDC(0.12,0.96,"CMS #it{#bf{Preliminary}}");
  textOnTop->DrawLatexNDC(0.58,0.96,"#bf{HGCAL OctTB @ H2,#pi^{-} beam}");
  
  
  textOnTop->SetTextSize(0.06);
  textOnTop->DrawLatexNDC(0.15,0.88,tex_method);
  // if(!strcmp(method,"fixed")) { textOnTop->DrawLatexNDC(0.15,0.88,tex_method); } 
  // else { textOnTop->SetTextSize(0.05); textOnTop->DrawLatexNDC(0.13,0.88,tex_method);}
  sprintf(tex_method,"#bf{Gaussian fit}");
  textOnTop->SetTextSize(0.055);
  textOnTop->DrawLatexNDC(0.15,0.80,tex_method);


  char *can_t = new char[1000];
  char *save_name = new char[1000];

  //sprintf(can_t,"./plots/response_and_resolution_plot/overlay_data_sim/resolution");
  sprintf(can_t,"./plots/response_resolution");
  if(save_){
    sprintf(save_name,"%s/%s.png",can_t,canvas_savename);
    mycanvas->SaveAs(save_name);
    sprintf(save_name,"%s/%s.pdf",can_t,canvas_savename);
    mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.jpg",can_t);
    // mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.gif",can_t);
    // mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.root",can_t);
    // mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.C",can_t);
    // mycanvas->SaveAs(save_name);
    // sprintf(save_name,"%s.pdf",can_t);
    // mycanvas->SaveAs(save_name);
  }

}



void run_all_resolution(bool save_ = false) {
  gROOT->SetBatch(1);
  overlay_resolution(1,"EE",save_);
  overlay_resolution(1,"FH",save_);
  overlay_resolution(1,"all",save_);
  
  
}


void run_all_response(bool save_ = false) {
  gROOT->SetBatch(1);
  overlay_response("EE",save_);
  overlay_response("FH",save_);
  overlay_response("all",save_);
  
  
}


