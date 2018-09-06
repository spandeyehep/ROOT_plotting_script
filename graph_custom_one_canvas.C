const int n_points=200;
//int point_col[4] = {kBlue, kRed, kBlack, kCyan};
int point_col[4] = {kBlue, kRed, kBlack, kMagenta};
//void graph_chip_wise(int n = 64, double x_val[4][n_points], double y_val[4][n_points], double y_err[4][n_points], int layer){
void graph_chip_wise(int n, double x_val[4][n_points], double y_val[4][n_points], double y_err[4][n_points], int layer){


  //For WebPage
  TCanvas *mycanvas = new TCanvas("mycanvas","mycanvas",800,550);

  //For slides
  // TCanvas *mycanvas = new TCanvas("mycanvas","mycanvas",400,275);

  //TLegend *legend = new TLegend(0.25,0.15,0.45,0.6);;
  //TLegend *legend = new TLegend(0.65,0.9,0.9,0.778);
  TLegend *legend = new TLegend(0.35,0.9,0.65,0.778);
  legend->SetNColumns(2);
  vector<TString> legName;
  legName.push_back("Chip 0");
  legName.push_back("Chip 1");
  legName.push_back("Chip 2");
  legName.push_back("Chip 3");
  
  // Instance of the graph
  TGraphErrors *graph_chip[4];
  // TGraphErrors *graph_chip1;
  // TGraphErrors *graph_chip2;
  // TGraphErrors *graph_chip3;
  // TGraphErrors *graph_chip4;

  //mycanvas->Divide(2,2);
  // Draw the graph !
  // graph->Draw("APE");
  //mycanvas->SetTitle("Layer 1");
  double x_val_temp[n_points];
  double y_val_temp[n_points];
  double y_err_temp[n_points];

  
  char *g_title = new char[100];
  for(int ii = 0; ii < 4; ii++) {
    //mycanvas->cd(ii+1);
    for(int jj = 0; jj < n; jj++) {
      x_val_temp[jj] = x_val[ii][jj];
      y_val_temp[jj] = y_val[ii][jj];
      y_err_temp[jj] = y_err[ii][jj];
    }
    graph_chip[ii] = new TGraphErrors(n,x_val_temp,y_val_temp,nullptr,y_err_temp);
    sprintf(g_title,"Layer %d;Channel;ADC counts/MIP",layer);
    graph_chip[ii]->SetTitle(g_title);

    // Make the plot esthetically better
    //graph_chip[ii]->SetMarkerStyle(kOpenCircle);
    graph_chip[ii]->SetMarkerStyle(kFullCircle);

    // graph_chip[ii]->SetMarkerColor(kBlue);
    // graph_chip[ii]->SetLineColor(kBlue);

    graph_chip[ii]->SetMarkerColor(point_col[ii]);
    graph_chip[ii]->SetLineColor(point_col[ii]);

    graph_chip[ii]->GetXaxis()->SetTitleSize(0.05);
    graph_chip[ii]->GetXaxis()->SetLabelSize(0.05);

    graph_chip[ii]->GetYaxis()->SetTitleSize(0.05);
    graph_chip[ii]->GetYaxis()->SetLabelSize(0.05);

    graph_chip[ii]->GetYaxis()->SetRangeUser(10.0,70.0);
    //gPad->SetTickx(2);
    gPad->SetGridx();
    gPad->SetGridy();

  
    // TLatex latex;// = new TLatex();
    // latex.DrawLatex(.5,.5,"yolo");
    // TLegend *legend1=new TLegend(0.25,0.15,0.45,0.6);

    //graph_chip[ii]->Draw("APE");
    if (ii == 0)
      graph_chip[ii]->Draw("APE");
    else
      graph_chip[ii]->Draw("PE sames");

    legend->AddEntry(graph_chip[ii],legName[ii],"pe");
    //legend->AddEntry(graph_chip[ii],"YOLO","e");
    // TPaveText *pt = new TPaveText(.05,.1,.95,.8);
    // pt->AddText("Layer-1");
    // pt->Draw();
    mycanvas->Modified();
  }

  legend->Draw();
  mycanvas->Modified();
  
  cout<<"Plotting FOR for Layer = "<<layer<<endl;
  char *can_t = new char[100];
  if(layer < 10)
    sprintf(can_t,"0%d_chip_wise_layer_%d.gif",layer,layer);
  else
    sprintf(can_t,"%d_chip_wise_layer_%d.gif",layer,layer);
  mycanvas->SaveAs(can_t);
  // Build and Draw a legend

  
  //   = new TGraphErrors(n_points,x_vals,y_vals,nullptr,y_errs);
  // graph->SetTitle("Measurement XYZ;length [cm];Arb.Units");


  // // The canvas on which we'll draw the graph
  // auto  mycanvas = new TCanvas();

  // // Draw the graph !
  // graph->Draw("APE");


}

void graph_custom(int layer)
{


  char* f_name = new char[200];
  //sprintf(f_name,"/home/shubham/work/HGCAL/CERNTB/txt_files/track_inclusion_errors/calib_file_layer_%d.txt",layer-1);
  sprintf(f_name,"/home/shubham/work/HGCAL/CERNTB/txt_files/track_inclusion_errors_v11/calib_file_layer_%d.txt",layer-1);
  cout<<"f_name: "<<f_name<<endl;
  std::ifstream in(f_name);
  
  if(in) cout<<"File Found!!!"<<endl;
  
  int layer_,chip_,channel_,en_chan,entry;
  float adc,adc_err,chi2,grass, grass_err, mpv;
  int find_;
  float min = 1000.0, max = -10.0;



  double x_vals_layer[n_points];
  double y_vals_layer[n_points];
  double y_errs_layer[n_points];

  double x_vals_chip[4][n_points];
  double y_vals_chip[4][n_points];
  double y_errs_chip[4][n_points];

  for(int ii = 0; ii < 4; ii++) {
    for(int jj = 0; jj < 64; jj++) {

      x_vals_chip[ii][jj] = 0.0;
      y_vals_chip[ii][jj] = 0.0;
      y_errs_chip[ii][jj] = 0.0;

    }
  }

  Double_t channel[200], ratio[200];
  int n = 128;
  int i = 0;
  while(in>>layer_>>chip_>>channel_>>en_chan>>adc>>chi2>>adc_err>>entry>>grass>>grass_err>>mpv) {
    if(entry < 20) {
      cout<<"Channel = "<<en_chan<<" contains entries less than 20, nothing to fit skipping.."<<endl;
      continue;
    }
    x_vals_chip[chip_][channel_] = channel_;
    y_vals_chip[chip_][channel_] = adc;
    y_errs_chip[chip_][channel_] = adc_err;
    //cout<<channel_<<" "<<adc
    x_vals_layer[i] = i;
    y_vals_layer[i] = adc;
    y_errs_layer[i] = adc_err;

    i++;
  }

  // cout<<"CHIP = 0"<<endl;
  // cout<<"x_vals_chip  y_vals_chip  y_errs_chip" << endl;
  // for(int jj = 0; jj < 64; jj++) {
  //   cout<<x_vals_chip[0][jj]<<" " << y_vals_chip[0][jj] << " " << y_errs_chip[0][jj] << endl;
  // }

  graph_chip_wise(64,x_vals_chip,y_vals_chip,y_errs_chip,layer);
  
  // for(int ii = 0; ii < 4; ii++) {
  //   for(int jj = 0; jj < 64; jj++) {
  //     cout<<x_vals_chip[ii][jj]<<" " << y_vals_chip[ii][jj] << " " << y_errs_chip[ii][jj] << endl;
  //   }
  // }

  /*  

  // Instance of the graph
  auto graph = new TGraphErrors(n_points,x_vals,y_vals,nullptr,y_errs);
  graph->SetTitle("Measurement XYZ;length [cm];Arb.Units");

  // Make the plot esthetically better
  graph->SetMarkerStyle(kOpenCircle);
  graph->SetMarkerColor(kBlue);
  graph->SetLineColor(kBlue);

  // The canvas on which we'll draw the graph
  auto  mycanvas = new TCanvas();

  // Draw the graph !
  graph->Draw("APE");

  // Define a linear function
  auto f = new TF1("Linear law","-1+x*5",.5,10.5);
  f->SetLineColor(kRed);
  f->SetLineStyle(2);
  f->Draw("Same");

  // Build and Draw a legend
  auto legend = new TLegend(.1,.7,.3,.9,"Lab. Lesson 1");
  legend->AddEntry(graph,"Exp. Points","PE");
  legend->AddEntry(f,"Th. Law", "L");
  legend->Draw();

  // Draw an arrow on the canvas
  auto arrow = new TArrow(8,8,6.2,23,0.02,"|>");
  arrow->SetLineWidth(2);
  arrow->Draw();

  // Add some text to the plot and highlight the 3rd label
  auto text = new TLatex(8.2,7.5,"#splitline{Maximum}{Deviation}");
  text->Draw();
  graph->GetXaxis()->ChangeLabel(3,-1,-1,-1,kRed);
  */
}


void draw_all(int start, int end) {
  for(int i = start; i <= end; i++) {
    graph_custom(i);
  }
}
