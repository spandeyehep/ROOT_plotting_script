#include "mapping.h"
void channel_map(int layer, int select)
//void channel_map()
{
//=========Macro generated from canvas: channel_map/channel_map
//=========  (Thu Jun 28 11:59:57 2018) by ROOT version6.09/02
   //TCanvas *channel_map = new TCanvas("channel_map", "channel_map",323,105,538,321);
	TCanvas *channel_map = new TCanvas("channel_map", "channel_map",900,750);
   channel_map->Range(-8.932475,-7.73575,8.932475,7.73575);
   channel_map->SetFillColor(0);
   channel_map->SetBorderMode(0);
   channel_map->SetBorderSize(2);
   channel_map->SetFrameBorderMode(0);
   channel_map->SetFrameBorderMode(0);
   channel_map->SetRightMargin(0.15);
   char* ch = new char[20];
   //int layer = 8;
   //int select = 3;
   switch(select) {
     case 1: sprintf(ch,"Channel Mapping, layer %d",layer); break;
     case 2: sprintf(ch,"ADC/MIP, layer %d",layer); break;
     case 3: sprintf(ch,"Chi2/NDF, layer %d",layer); break;
     case 4: sprintf(ch,"Bkg value, layer %d",layer); break;
     case 5:  sprintf(ch,"Error on Bkg value, layer %d",layer); break;
     }

   //sprintf(ch,"Bkg values, layer %d",layer);
   //sprintf(ch,"Channel Mapping, layer %d",layer);
   //TH2Poly *ChannelMapping = new TH2Poly("ChannelMapping", "ChannelMapping", 25, -7.14598, 7.14598, 25, -6.1886, 6.1886);
   TH2Poly *ChannelMapping = new TH2Poly("ChannelMapping", ch, 25, -7.14598, 7.14598, 25, -6.1886, 6.1886);
   
   Double_t Graph_fx1[4] = {
   6.171528,
   6.496345,
   7.14598,
   6.496345};
   Double_t Graph_fy1[4] = {
   0.5626,
   -1.166027e-08,
   -1.282629e-08,
   1.1252};
   TGraph *graph = new TGraph(4,Graph_fx1,Graph_fy1);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,6.074083,7.243425);
   Graph_Graph1->SetMinimum(-0.11252);
   Graph_Graph1->SetMaximum(1.23772);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx2[4] = {
   6.171528,
   6.496345,
   7.14598,
   6.496345};
   Double_t Graph_fy2[4] = {
   -0.5626,
   -1.1252,
   -1.282629e-08,
   -1.166027e-08};
   graph = new TGraph(4,Graph_fx2,Graph_fy2);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,6.074083,7.243425);
   Graph_Graph2->SetMinimum(-1.23772);
   Graph_Graph2->SetMaximum(0.11252);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx3[4] = {
   5.197076,
   5.521893,
   6.171528,
   5.521893};
   Double_t Graph_fy3[4] = {
   2.2504,
   1.6878,
   1.6878,
   2.813};
   graph = new TGraph(4,Graph_fx3,Graph_fy3);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,5.099631,6.268973);
   Graph_Graph3->SetMinimum(1.57528);
   Graph_Graph3->SetMaximum(2.92552);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph3->SetLineColor(ci);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx4[6] = {
   5.197076,
   5.521893,
   6.171528,
   6.496345,
   6.171528,
   5.521893};
   Double_t Graph_fy4[6] = {
   1.1252,
   0.5626,
   0.5626,
   1.1252,
   1.6878,
   1.6878};
   graph = new TGraph(6,Graph_fx4,Graph_fy4);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph4 = new TH1F("Graph_Graph4","Graph",100,5.067149,6.626272);
   Graph_Graph4->SetMinimum(0.45008);
   Graph_Graph4->SetMaximum(1.80032);
   Graph_Graph4->SetDirectory(0);
   Graph_Graph4->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph4->SetLineColor(ci);
   Graph_Graph4->GetXaxis()->SetLabelFont(42);
   Graph_Graph4->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetXaxis()->SetTitleFont(42);
   Graph_Graph4->GetYaxis()->SetLabelFont(42);
   Graph_Graph4->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetYaxis()->SetTitleFont(42);
   Graph_Graph4->GetZaxis()->SetLabelFont(42);
   Graph_Graph4->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph4->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph4);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx5[6] = {
   5.197076,
   5.521893,
   6.171528,
   6.496345,
   6.171528,
   5.521893};
   Double_t Graph_fy5[6] = {
   -9.328214e-09,
   -0.5626,
   -0.5626,
   -1.166027e-08,
   0.5626,
   0.5626};
   graph = new TGraph(6,Graph_fx5,Graph_fy5);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","Graph",100,5.067149,6.626272);
   Graph_Graph5->SetMinimum(-0.67512);
   Graph_Graph5->SetMaximum(0.67512);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph5->SetLineColor(ci);
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph5);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx6[6] = {
   5.197076,
   5.521893,
   6.171528,
   6.496345,
   6.171528,
   5.521893};
   Double_t Graph_fy6[6] = {
   -1.1252,
   -1.6878,
   -1.6878,
   -1.1252,
   -0.5626,
   -0.5626};
   graph = new TGraph(6,Graph_fx6,Graph_fy6);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Graph",100,5.067149,6.626272);
   Graph_Graph6->SetMinimum(-1.80032);
   Graph_Graph6->SetMaximum(-0.45008);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph6->SetLineColor(ci);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph6);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx7[4] = {
   5.197076,
   5.521893,
   6.171528,
   5.521893};
   Double_t Graph_fy7[4] = {
   -2.2504,
   -2.813,
   -1.6878,
   -1.6878};
   graph = new TGraph(4,Graph_fx7,Graph_fy7);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","Graph",100,5.099631,6.268973);
   Graph_Graph7->SetMinimum(-2.92552);
   Graph_Graph7->SetMaximum(-1.57528);
   Graph_Graph7->SetDirectory(0);
   Graph_Graph7->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph7->SetLineColor(ci);
   Graph_Graph7->GetXaxis()->SetLabelFont(42);
   Graph_Graph7->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetXaxis()->SetTitleFont(42);
   Graph_Graph7->GetYaxis()->SetLabelFont(42);
   Graph_Graph7->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetYaxis()->SetTitleFont(42);
   Graph_Graph7->GetZaxis()->SetLabelFont(42);
   Graph_Graph7->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph7->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph7);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx8[4] = {
   4.222624,
   4.547442,
   5.197076,
   4.547442};
   Double_t Graph_fy8[4] = {
   3.9382,
   3.3756,
   3.3756,
   4.5008};
   graph = new TGraph(4,Graph_fx8,Graph_fy8);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph8 = new TH1F("Graph_Graph8","Graph",100,4.125179,5.294521);
   Graph_Graph8->SetMinimum(3.26308);
   Graph_Graph8->SetMaximum(4.61332);
   Graph_Graph8->SetDirectory(0);
   Graph_Graph8->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph8->SetLineColor(ci);
   Graph_Graph8->GetXaxis()->SetLabelFont(42);
   Graph_Graph8->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph8->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph8->GetXaxis()->SetTitleFont(42);
   Graph_Graph8->GetYaxis()->SetLabelFont(42);
   Graph_Graph8->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph8->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph8->GetYaxis()->SetTitleFont(42);
   Graph_Graph8->GetZaxis()->SetLabelFont(42);
   Graph_Graph8->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph8->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph8);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx9[6] = {
   4.222624,
   4.547442,
   5.197076,
   5.521893,
   5.197076,
   4.547442};
   Double_t Graph_fy9[6] = {
   2.813,
   2.2504,
   2.2504,
   2.813,
   3.3756,
   3.3756};
   graph = new TGraph(6,Graph_fx9,Graph_fy9);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph9 = new TH1F("Graph_Graph9","Graph",100,4.092697,5.65182);
   Graph_Graph9->SetMinimum(2.13788);
   Graph_Graph9->SetMaximum(3.48812);
   Graph_Graph9->SetDirectory(0);
   Graph_Graph9->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph9->SetLineColor(ci);
   Graph_Graph9->GetXaxis()->SetLabelFont(42);
   Graph_Graph9->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetXaxis()->SetTitleFont(42);
   Graph_Graph9->GetYaxis()->SetLabelFont(42);
   Graph_Graph9->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetYaxis()->SetTitleFont(42);
   Graph_Graph9->GetZaxis()->SetLabelFont(42);
   Graph_Graph9->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph9->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph9->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph9);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx10[6] = {
   4.222624,
   4.547442,
   5.197076,
   5.521893,
   5.197076,
   4.547442};
   Double_t Graph_fy10[6] = {
   1.6878,
   1.1252,
   1.1252,
   1.6878,
   2.2504,
   2.2504};
   graph = new TGraph(6,Graph_fx10,Graph_fy10);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph10 = new TH1F("Graph_Graph10","Graph",100,4.092697,5.65182);
   Graph_Graph10->SetMinimum(1.01268);
   Graph_Graph10->SetMaximum(2.36292);
   Graph_Graph10->SetDirectory(0);
   Graph_Graph10->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph10->SetLineColor(ci);
   Graph_Graph10->GetXaxis()->SetLabelFont(42);
   Graph_Graph10->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph10->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph10->GetXaxis()->SetTitleFont(42);
   Graph_Graph10->GetYaxis()->SetLabelFont(42);
   Graph_Graph10->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph10->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph10->GetYaxis()->SetTitleFont(42);
   Graph_Graph10->GetZaxis()->SetLabelFont(42);
   Graph_Graph10->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph10->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph10->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph10);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx11[6] = {
   4.222624,
   4.547442,
   5.197076,
   5.521893,
   5.197076,
   4.547442};
   Double_t Graph_fy11[6] = {
   0.5626,
   -8.162187e-09,
   -9.328214e-09,
   0.5626,
   1.1252,
   1.1252};
   graph = new TGraph(6,Graph_fx11,Graph_fy11);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph11 = new TH1F("Graph_Graph11","Graph",100,4.092697,5.65182);
   Graph_Graph11->SetMinimum(-0.11252);
   Graph_Graph11->SetMaximum(1.23772);
   Graph_Graph11->SetDirectory(0);
   Graph_Graph11->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph11->SetLineColor(ci);
   Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph11->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph11->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph11->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph11);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx12[6] = {
   4.222624,
   4.547441,
   5.197076,
   5.521893,
   5.197076,
   4.547442};
   Double_t Graph_fy12[6] = {
   -0.5626,
   -1.1252,
   -1.1252,
   -0.5626,
   -9.328214e-09,
   -8.162187e-09};
   graph = new TGraph(6,Graph_fx12,Graph_fy12);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph12 = new TH1F("Graph_Graph12","Graph",100,4.092697,5.65182);
   Graph_Graph12->SetMinimum(-1.23772);
   Graph_Graph12->SetMaximum(0.11252);
   Graph_Graph12->SetDirectory(0);
   Graph_Graph12->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph12->SetLineColor(ci);
   Graph_Graph12->GetXaxis()->SetLabelFont(42);
   Graph_Graph12->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph12->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph12->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph12->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph12->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph12->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph12);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx13[6] = {
   4.222624,
   4.547441,
   5.197076,
   5.521893,
   5.197076,
   4.547441};
   Double_t Graph_fy13[6] = {
   -1.6878,
   -2.2504,
   -2.2504,
   -1.6878,
   -1.1252,
   -1.1252};
   graph = new TGraph(6,Graph_fx13,Graph_fy13);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph13 = new TH1F("Graph_Graph13","Graph",100,4.092697,5.65182);
   Graph_Graph13->SetMinimum(-2.36292);
   Graph_Graph13->SetMaximum(-1.01268);
   Graph_Graph13->SetDirectory(0);
   Graph_Graph13->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph13->SetLineColor(ci);
   Graph_Graph13->GetXaxis()->SetLabelFont(42);
   Graph_Graph13->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetXaxis()->SetTitleFont(42);
   Graph_Graph13->GetYaxis()->SetLabelFont(42);
   Graph_Graph13->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetYaxis()->SetTitleFont(42);
   Graph_Graph13->GetZaxis()->SetLabelFont(42);
   Graph_Graph13->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph13->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph13->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph13);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx14[6] = {
   4.222624,
   4.547441,
   5.197076,
   5.521893,
   5.197076,
   4.547441};
   Double_t Graph_fy14[6] = {
   -2.813,
   -3.3756,
   -3.3756,
   -2.813,
   -2.2504,
   -2.2504};
   graph = new TGraph(6,Graph_fx14,Graph_fy14);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph14 = new TH1F("Graph_Graph14","Graph",100,4.092697,5.65182);
   Graph_Graph14->SetMinimum(-3.48812);
   Graph_Graph14->SetMaximum(-2.13788);
   Graph_Graph14->SetDirectory(0);
   Graph_Graph14->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph14->SetLineColor(ci);
   Graph_Graph14->GetXaxis()->SetLabelFont(42);
   Graph_Graph14->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph14->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph14->GetXaxis()->SetTitleFont(42);
   Graph_Graph14->GetYaxis()->SetLabelFont(42);
   Graph_Graph14->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph14->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph14->GetYaxis()->SetTitleFont(42);
   Graph_Graph14->GetZaxis()->SetLabelFont(42);
   Graph_Graph14->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph14->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph14->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph14);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx15[4] = {
   4.222624,
   4.547441,
   5.197076,
   4.547441};
   Double_t Graph_fy15[4] = {
   -3.9382,
   -4.5008,
   -3.3756,
   -3.3756};
   graph = new TGraph(4,Graph_fx15,Graph_fy15);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph15 = new TH1F("Graph_Graph15","Graph",100,4.125179,5.294521);
   Graph_Graph15->SetMinimum(-4.61332);
   Graph_Graph15->SetMaximum(-3.26308);
   Graph_Graph15->SetDirectory(0);
   Graph_Graph15->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph15->SetLineColor(ci);
   Graph_Graph15->GetXaxis()->SetLabelFont(42);
   Graph_Graph15->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetXaxis()->SetTitleFont(42);
   Graph_Graph15->GetYaxis()->SetLabelFont(42);
   Graph_Graph15->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetYaxis()->SetTitleFont(42);
   Graph_Graph15->GetZaxis()->SetLabelFont(42);
   Graph_Graph15->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph15->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph15->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph15);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx16[4] = {
   3.248173,
   3.57299,
   4.222624,
   3.57299};
   Double_t Graph_fy16[4] = {
   5.626,
   5.0634,
   5.0634,
   6.1886};
   graph = new TGraph(4,Graph_fx16,Graph_fy16);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph16 = new TH1F("Graph_Graph16","Graph",100,3.150727,4.320069);
   Graph_Graph16->SetMinimum(4.95088);
   Graph_Graph16->SetMaximum(6.30112);
   Graph_Graph16->SetDirectory(0);
   Graph_Graph16->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph16->SetLineColor(ci);
   Graph_Graph16->GetXaxis()->SetLabelFont(42);
   Graph_Graph16->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph16->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph16->GetXaxis()->SetTitleFont(42);
   Graph_Graph16->GetYaxis()->SetLabelFont(42);
   Graph_Graph16->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph16->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph16->GetYaxis()->SetTitleFont(42);
   Graph_Graph16->GetZaxis()->SetLabelFont(42);
   Graph_Graph16->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph16->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph16->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph16);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx17[6] = {
   3.248173,
   3.57299,
   4.222624,
   4.547442,
   4.222624,
   3.57299};
   Double_t Graph_fy17[6] = {
   4.5008,
   3.9382,
   3.9382,
   4.5008,
   5.0634,
   5.0634};
   graph = new TGraph(6,Graph_fx17,Graph_fy17);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph17 = new TH1F("Graph_Graph17","Graph",100,3.118246,4.677368);
   Graph_Graph17->SetMinimum(3.82568);
   Graph_Graph17->SetMaximum(5.17592);
   Graph_Graph17->SetDirectory(0);
   Graph_Graph17->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph17->SetLineColor(ci);
   Graph_Graph17->GetXaxis()->SetLabelFont(42);
   Graph_Graph17->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph17->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph17->GetXaxis()->SetTitleFont(42);
   Graph_Graph17->GetYaxis()->SetLabelFont(42);
   Graph_Graph17->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph17->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph17->GetYaxis()->SetTitleFont(42);
   Graph_Graph17->GetZaxis()->SetLabelFont(42);
   Graph_Graph17->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph17->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph17->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph17);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx18[6] = {
   3.248173,
   3.57299,
   4.222624,
   4.547442,
   4.222624,
   3.57299};
   Double_t Graph_fy18[6] = {
   3.3756,
   2.813,
   2.813,
   3.3756,
   3.9382,
   3.9382};
   graph = new TGraph(6,Graph_fx18,Graph_fy18);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph18 = new TH1F("Graph_Graph18","Graph",100,3.118246,4.677368);
   Graph_Graph18->SetMinimum(2.70048);
   Graph_Graph18->SetMaximum(4.05072);
   Graph_Graph18->SetDirectory(0);
   Graph_Graph18->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph18->SetLineColor(ci);
   Graph_Graph18->GetXaxis()->SetLabelFont(42);
   Graph_Graph18->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph18->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph18->GetXaxis()->SetTitleFont(42);
   Graph_Graph18->GetYaxis()->SetLabelFont(42);
   Graph_Graph18->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph18->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph18->GetYaxis()->SetTitleFont(42);
   Graph_Graph18->GetZaxis()->SetLabelFont(42);
   Graph_Graph18->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph18->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph18->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph18);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx19[6] = {
   3.248173,
   3.57299,
   4.222624,
   4.547442,
   4.222624,
   3.57299};
   Double_t Graph_fy19[6] = {
   2.2504,
   1.6878,
   1.6878,
   2.2504,
   2.813,
   2.813};
   graph = new TGraph(6,Graph_fx19,Graph_fy19);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph19 = new TH1F("Graph_Graph19","Graph",100,3.118246,4.677368);
   Graph_Graph19->SetMinimum(1.57528);
   Graph_Graph19->SetMaximum(2.92552);
   Graph_Graph19->SetDirectory(0);
   Graph_Graph19->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph19->SetLineColor(ci);
   Graph_Graph19->GetXaxis()->SetLabelFont(42);
   Graph_Graph19->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph19->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph19->GetXaxis()->SetTitleFont(42);
   Graph_Graph19->GetYaxis()->SetLabelFont(42);
   Graph_Graph19->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph19->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph19->GetYaxis()->SetTitleFont(42);
   Graph_Graph19->GetZaxis()->SetLabelFont(42);
   Graph_Graph19->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph19->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph19->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph19);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx20[6] = {
   3.248173,
   3.57299,
   4.222624,
   4.547442,
   4.222624,
   3.57299};
   Double_t Graph_fy20[6] = {
   1.1252,
   0.5626,
   0.5626,
   1.1252,
   1.6878,
   1.6878};
   graph = new TGraph(6,Graph_fx20,Graph_fy20);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph20 = new TH1F("Graph_Graph20","Graph",100,3.118246,4.677368);
   Graph_Graph20->SetMinimum(0.45008);
   Graph_Graph20->SetMaximum(1.80032);
   Graph_Graph20->SetDirectory(0);
   Graph_Graph20->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph20->SetLineColor(ci);
   Graph_Graph20->GetXaxis()->SetLabelFont(42);
   Graph_Graph20->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph20->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph20->GetXaxis()->SetTitleFont(42);
   Graph_Graph20->GetYaxis()->SetLabelFont(42);
   Graph_Graph20->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph20->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph20->GetYaxis()->SetTitleFont(42);
   Graph_Graph20->GetZaxis()->SetLabelFont(42);
   Graph_Graph20->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph20->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph20->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph20);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx21[6] = {
   3.248173,
   3.57299,
   4.222624,
   4.547442,
   4.222624,
   3.57299};
   Double_t Graph_fy21[6] = {
   -5.830134e-09,
   -0.5626,
   -0.5626,
   -8.162187e-09,
   0.5626,
   0.5626};
   graph = new TGraph(6,Graph_fx21,Graph_fy21);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph21 = new TH1F("Graph_Graph21","Graph",100,3.118246,4.677368);
   Graph_Graph21->SetMinimum(-0.67512);
   Graph_Graph21->SetMaximum(0.67512);
   Graph_Graph21->SetDirectory(0);
   Graph_Graph21->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph21->SetLineColor(ci);
   Graph_Graph21->GetXaxis()->SetLabelFont(42);
   Graph_Graph21->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph21->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph21->GetXaxis()->SetTitleFont(42);
   Graph_Graph21->GetYaxis()->SetLabelFont(42);
   Graph_Graph21->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph21->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph21->GetYaxis()->SetTitleFont(42);
   Graph_Graph21->GetZaxis()->SetLabelFont(42);
   Graph_Graph21->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph21->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph21->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph21);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx22[6] = {
   3.248172,
   3.57299,
   4.222624,
   4.547441,
   4.222624,
   3.57299};
   Double_t Graph_fy22[6] = {
   -1.1252,
   -1.6878,
   -1.6878,
   -1.1252,
   -0.5626,
   -0.5626};
   graph = new TGraph(6,Graph_fx22,Graph_fy22);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph22 = new TH1F("Graph_Graph22","Graph",100,3.118246,4.677368);
   Graph_Graph22->SetMinimum(-1.80032);
   Graph_Graph22->SetMaximum(-0.45008);
   Graph_Graph22->SetDirectory(0);
   Graph_Graph22->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph22->SetLineColor(ci);
   Graph_Graph22->GetXaxis()->SetLabelFont(42);
   Graph_Graph22->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph22->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph22->GetXaxis()->SetTitleFont(42);
   Graph_Graph22->GetYaxis()->SetLabelFont(42);
   Graph_Graph22->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph22->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph22->GetYaxis()->SetTitleFont(42);
   Graph_Graph22->GetZaxis()->SetLabelFont(42);
   Graph_Graph22->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph22->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph22->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph22);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx23[6] = {
   3.248172,
   3.57299,
   4.222624,
   4.547441,
   4.222624,
   3.57299};
   Double_t Graph_fy23[6] = {
   -2.2504,
   -2.813,
   -2.813,
   -2.2504,
   -1.6878,
   -1.6878};
   graph = new TGraph(6,Graph_fx23,Graph_fy23);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph23 = new TH1F("Graph_Graph23","Graph",100,3.118246,4.677368);
   Graph_Graph23->SetMinimum(-2.92552);
   Graph_Graph23->SetMaximum(-1.57528);
   Graph_Graph23->SetDirectory(0);
   Graph_Graph23->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph23->SetLineColor(ci);
   Graph_Graph23->GetXaxis()->SetLabelFont(42);
   Graph_Graph23->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph23->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph23->GetXaxis()->SetTitleFont(42);
   Graph_Graph23->GetYaxis()->SetLabelFont(42);
   Graph_Graph23->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph23->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph23->GetYaxis()->SetTitleFont(42);
   Graph_Graph23->GetZaxis()->SetLabelFont(42);
   Graph_Graph23->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph23->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph23->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph23);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx24[6] = {
   3.248172,
   3.57299,
   4.222624,
   4.547441,
   4.222624,
   3.57299};
   Double_t Graph_fy24[6] = {
   -3.3756,
   -3.9382,
   -3.9382,
   -3.3756,
   -2.813,
   -2.813};
   graph = new TGraph(6,Graph_fx24,Graph_fy24);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph24 = new TH1F("Graph_Graph24","Graph",100,3.118246,4.677368);
   Graph_Graph24->SetMinimum(-4.05072);
   Graph_Graph24->SetMaximum(-2.70048);
   Graph_Graph24->SetDirectory(0);
   Graph_Graph24->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph24->SetLineColor(ci);
   Graph_Graph24->GetXaxis()->SetLabelFont(42);
   Graph_Graph24->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph24->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph24->GetXaxis()->SetTitleFont(42);
   Graph_Graph24->GetYaxis()->SetLabelFont(42);
   Graph_Graph24->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph24->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph24->GetYaxis()->SetTitleFont(42);
   Graph_Graph24->GetZaxis()->SetLabelFont(42);
   Graph_Graph24->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph24->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph24->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph24);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx25[6] = {
   3.248172,
   3.57299,
   4.222624,
   4.547441,
   4.222624,
   3.57299};
   Double_t Graph_fy25[6] = {
   -4.5008,
   -5.0634,
   -5.0634,
   -4.5008,
   -3.9382,
   -3.9382};
   graph = new TGraph(6,Graph_fx25,Graph_fy25);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph25 = new TH1F("Graph_Graph25","Graph",100,3.118246,4.677368);
   Graph_Graph25->SetMinimum(-5.17592);
   Graph_Graph25->SetMaximum(-3.82568);
   Graph_Graph25->SetDirectory(0);
   Graph_Graph25->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph25->SetLineColor(ci);
   Graph_Graph25->GetXaxis()->SetLabelFont(42);
   Graph_Graph25->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph25->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph25->GetXaxis()->SetTitleFont(42);
   Graph_Graph25->GetYaxis()->SetLabelFont(42);
   Graph_Graph25->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph25->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph25->GetYaxis()->SetTitleFont(42);
   Graph_Graph25->GetZaxis()->SetLabelFont(42);
   Graph_Graph25->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph25->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph25->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph25);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx26[4] = {
   3.248172,
   3.57299,
   4.222624,
   3.57299};
   Double_t Graph_fy26[4] = {
   -5.626,
   -6.1886,
   -5.0634,
   -5.0634};
   graph = new TGraph(4,Graph_fx26,Graph_fy26);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph26 = new TH1F("Graph_Graph26","Graph",100,3.150727,4.320069);
   Graph_Graph26->SetMinimum(-6.30112);
   Graph_Graph26->SetMaximum(-4.95088);
   Graph_Graph26->SetDirectory(0);
   Graph_Graph26->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph26->SetLineColor(ci);
   Graph_Graph26->GetXaxis()->SetLabelFont(42);
   Graph_Graph26->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph26->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph26->GetXaxis()->SetTitleFont(42);
   Graph_Graph26->GetYaxis()->SetLabelFont(42);
   Graph_Graph26->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph26->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph26->GetYaxis()->SetTitleFont(42);
   Graph_Graph26->GetZaxis()->SetLabelFont(42);
   Graph_Graph26->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph26->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph26->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph26);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx27[4] = {
   2.273721,
   2.598538,
   3.248173,
   3.57299};
   Double_t Graph_fy27[4] = {
   6.1886,
   5.626,
   5.626,
   6.1886};
   graph = new TGraph(4,Graph_fx27,Graph_fy27);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph27 = new TH1F("Graph_Graph27","Graph",100,2.143794,3.702917);
   Graph_Graph27->SetMinimum(5.56974);
   Graph_Graph27->SetMaximum(6.24486);
   Graph_Graph27->SetDirectory(0);
   Graph_Graph27->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph27->SetLineColor(ci);
   Graph_Graph27->GetXaxis()->SetLabelFont(42);
   Graph_Graph27->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph27->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph27->GetXaxis()->SetTitleFont(42);
   Graph_Graph27->GetYaxis()->SetLabelFont(42);
   Graph_Graph27->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph27->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph27->GetYaxis()->SetTitleFont(42);
   Graph_Graph27->GetZaxis()->SetLabelFont(42);
   Graph_Graph27->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph27->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph27->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph27);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx28[6] = {
   2.273721,
   2.598538,
   3.248173,
   3.57299,
   3.248173,
   2.598538};
   Double_t Graph_fy28[6] = {
   5.0634,
   4.5008,
   4.5008,
   5.0634,
   5.626,
   5.626};
   graph = new TGraph(6,Graph_fx28,Graph_fy28);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph28 = new TH1F("Graph_Graph28","Graph",100,2.143794,3.702917);
   Graph_Graph28->SetMinimum(4.38828);
   Graph_Graph28->SetMaximum(5.73852);
   Graph_Graph28->SetDirectory(0);
   Graph_Graph28->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph28->SetLineColor(ci);
   Graph_Graph28->GetXaxis()->SetLabelFont(42);
   Graph_Graph28->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph28->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph28->GetXaxis()->SetTitleFont(42);
   Graph_Graph28->GetYaxis()->SetLabelFont(42);
   Graph_Graph28->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph28->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph28->GetYaxis()->SetTitleFont(42);
   Graph_Graph28->GetZaxis()->SetLabelFont(42);
   Graph_Graph28->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph28->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph28->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph28);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx29[6] = {
   2.273721,
   2.598538,
   3.248173,
   3.57299,
   3.248173,
   2.598538};
   Double_t Graph_fy29[6] = {
   3.9382,
   3.3756,
   3.3756,
   3.9382,
   4.5008,
   4.5008};
   graph = new TGraph(6,Graph_fx29,Graph_fy29);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph29 = new TH1F("Graph_Graph29","Graph",100,2.143794,3.702917);
   Graph_Graph29->SetMinimum(3.26308);
   Graph_Graph29->SetMaximum(4.61332);
   Graph_Graph29->SetDirectory(0);
   Graph_Graph29->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph29->SetLineColor(ci);
   Graph_Graph29->GetXaxis()->SetLabelFont(42);
   Graph_Graph29->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph29->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph29->GetXaxis()->SetTitleFont(42);
   Graph_Graph29->GetYaxis()->SetLabelFont(42);
   Graph_Graph29->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph29->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph29->GetYaxis()->SetTitleFont(42);
   Graph_Graph29->GetZaxis()->SetLabelFont(42);
   Graph_Graph29->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph29->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph29->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph29);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx30[6] = {
   2.273721,
   2.598538,
   3.248173,
   3.57299,
   3.248173,
   2.598538};
   Double_t Graph_fy30[6] = {
   2.813,
   2.2504,
   2.2504,
   2.813,
   3.3756,
   3.3756};
   graph = new TGraph(6,Graph_fx30,Graph_fy30);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph30 = new TH1F("Graph_Graph30","Graph",100,2.143794,3.702917);
   Graph_Graph30->SetMinimum(2.13788);
   Graph_Graph30->SetMaximum(3.48812);
   Graph_Graph30->SetDirectory(0);
   Graph_Graph30->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph30->SetLineColor(ci);
   Graph_Graph30->GetXaxis()->SetLabelFont(42);
   Graph_Graph30->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph30->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph30->GetXaxis()->SetTitleFont(42);
   Graph_Graph30->GetYaxis()->SetLabelFont(42);
   Graph_Graph30->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph30->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph30->GetYaxis()->SetTitleFont(42);
   Graph_Graph30->GetZaxis()->SetLabelFont(42);
   Graph_Graph30->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph30->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph30->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph30);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx31[6] = {
   2.273721,
   2.598538,
   3.248173,
   3.57299,
   3.248173,
   2.598538};
   Double_t Graph_fy31[6] = {
   1.6878,
   1.1252,
   1.1252,
   1.6878,
   2.2504,
   2.2504};
   graph = new TGraph(6,Graph_fx31,Graph_fy31);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph31 = new TH1F("Graph_Graph31","Graph",100,2.143794,3.702917);
   Graph_Graph31->SetMinimum(1.01268);
   Graph_Graph31->SetMaximum(2.36292);
   Graph_Graph31->SetDirectory(0);
   Graph_Graph31->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph31->SetLineColor(ci);
   Graph_Graph31->GetXaxis()->SetLabelFont(42);
   Graph_Graph31->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph31->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph31->GetXaxis()->SetTitleFont(42);
   Graph_Graph31->GetYaxis()->SetLabelFont(42);
   Graph_Graph31->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph31->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph31->GetYaxis()->SetTitleFont(42);
   Graph_Graph31->GetZaxis()->SetLabelFont(42);
   Graph_Graph31->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph31->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph31->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph31);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx32[6] = {
   2.273721,
   2.598538,
   3.248173,
   3.57299,
   3.248173,
   2.598538};
   Double_t Graph_fy32[6] = {
   0.5626,
   -4.664107e-09,
   -5.830134e-09,
   0.5626,
   1.1252,
   1.1252};
   graph = new TGraph(6,Graph_fx32,Graph_fy32);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph32 = new TH1F("Graph_Graph32","Graph",100,2.143794,3.702917);
   Graph_Graph32->SetMinimum(-0.11252);
   Graph_Graph32->SetMaximum(1.23772);
   Graph_Graph32->SetDirectory(0);
   Graph_Graph32->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph32->SetLineColor(ci);
   Graph_Graph32->GetXaxis()->SetLabelFont(42);
   Graph_Graph32->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph32->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph32->GetXaxis()->SetTitleFont(42);
   Graph_Graph32->GetYaxis()->SetLabelFont(42);
   Graph_Graph32->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph32->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph32->GetYaxis()->SetTitleFont(42);
   Graph_Graph32->GetZaxis()->SetLabelFont(42);
   Graph_Graph32->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph32->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph32->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph32);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx33[6] = {
   2.273721,
   2.598538,
   3.248172,
   3.57299,
   3.248173,
   2.598538};
   Double_t Graph_fy33[6] = {
   -0.5626,
   -1.1252,
   -1.1252,
   -0.5626,
   -5.830134e-09,
   -4.664107e-09};
   graph = new TGraph(6,Graph_fx33,Graph_fy33);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph33 = new TH1F("Graph_Graph33","Graph",100,2.143794,3.702917);
   Graph_Graph33->SetMinimum(-1.23772);
   Graph_Graph33->SetMaximum(0.11252);
   Graph_Graph33->SetDirectory(0);
   Graph_Graph33->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph33->SetLineColor(ci);
   Graph_Graph33->GetXaxis()->SetLabelFont(42);
   Graph_Graph33->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph33->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph33->GetXaxis()->SetTitleFont(42);
   Graph_Graph33->GetYaxis()->SetLabelFont(42);
   Graph_Graph33->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph33->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph33->GetYaxis()->SetTitleFont(42);
   Graph_Graph33->GetZaxis()->SetLabelFont(42);
   Graph_Graph33->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph33->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph33->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph33);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx34[6] = {
   2.273721,
   2.598538,
   3.248172,
   3.57299,
   3.248172,
   2.598538};
   Double_t Graph_fy34[6] = {
   -1.6878,
   -2.2504,
   -2.2504,
   -1.6878,
   -1.1252,
   -1.1252};
   graph = new TGraph(6,Graph_fx34,Graph_fy34);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph34 = new TH1F("Graph_Graph34","Graph",100,2.143794,3.702917);
   Graph_Graph34->SetMinimum(-2.36292);
   Graph_Graph34->SetMaximum(-1.01268);
   Graph_Graph34->SetDirectory(0);
   Graph_Graph34->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph34->SetLineColor(ci);
   Graph_Graph34->GetXaxis()->SetLabelFont(42);
   Graph_Graph34->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph34->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph34->GetXaxis()->SetTitleFont(42);
   Graph_Graph34->GetYaxis()->SetLabelFont(42);
   Graph_Graph34->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph34->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph34->GetYaxis()->SetTitleFont(42);
   Graph_Graph34->GetZaxis()->SetLabelFont(42);
   Graph_Graph34->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph34->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph34->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph34);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx35[6] = {
   2.273721,
   2.598538,
   3.248172,
   3.57299,
   3.248172,
   2.598538};
   Double_t Graph_fy35[6] = {
   -2.813,
   -3.3756,
   -3.3756,
   -2.813,
   -2.2504,
   -2.2504};
   graph = new TGraph(6,Graph_fx35,Graph_fy35);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph35 = new TH1F("Graph_Graph35","Graph",100,2.143794,3.702917);
   Graph_Graph35->SetMinimum(-3.48812);
   Graph_Graph35->SetMaximum(-2.13788);
   Graph_Graph35->SetDirectory(0);
   Graph_Graph35->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph35->SetLineColor(ci);
   Graph_Graph35->GetXaxis()->SetLabelFont(42);
   Graph_Graph35->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph35->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph35->GetXaxis()->SetTitleFont(42);
   Graph_Graph35->GetYaxis()->SetLabelFont(42);
   Graph_Graph35->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph35->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph35->GetYaxis()->SetTitleFont(42);
   Graph_Graph35->GetZaxis()->SetLabelFont(42);
   Graph_Graph35->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph35->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph35->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph35);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx36[6] = {
   2.273721,
   2.598538,
   3.248172,
   3.57299,
   3.248172,
   2.598538};
   Double_t Graph_fy36[6] = {
   -3.9382,
   -4.5008,
   -4.5008,
   -3.9382,
   -3.3756,
   -3.3756};
   graph = new TGraph(6,Graph_fx36,Graph_fy36);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph36 = new TH1F("Graph_Graph36","Graph",100,2.143794,3.702917);
   Graph_Graph36->SetMinimum(-4.61332);
   Graph_Graph36->SetMaximum(-3.26308);
   Graph_Graph36->SetDirectory(0);
   Graph_Graph36->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph36->SetLineColor(ci);
   Graph_Graph36->GetXaxis()->SetLabelFont(42);
   Graph_Graph36->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph36->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph36->GetXaxis()->SetTitleFont(42);
   Graph_Graph36->GetYaxis()->SetLabelFont(42);
   Graph_Graph36->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph36->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph36->GetYaxis()->SetTitleFont(42);
   Graph_Graph36->GetZaxis()->SetLabelFont(42);
   Graph_Graph36->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph36->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph36->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph36);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx37[6] = {
   2.273721,
   2.598538,
   3.248172,
   3.57299,
   3.248172,
   2.598538};
   Double_t Graph_fy37[6] = {
   -5.0634,
   -5.626,
   -5.626,
   -5.0634,
   -4.5008,
   -4.5008};
   graph = new TGraph(6,Graph_fx37,Graph_fy37);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph37 = new TH1F("Graph_Graph37","Graph",100,2.143794,3.702917);
   Graph_Graph37->SetMinimum(-5.73852);
   Graph_Graph37->SetMaximum(-4.38828);
   Graph_Graph37->SetDirectory(0);
   Graph_Graph37->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph37->SetLineColor(ci);
   Graph_Graph37->GetXaxis()->SetLabelFont(42);
   Graph_Graph37->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph37->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph37->GetXaxis()->SetTitleFont(42);
   Graph_Graph37->GetYaxis()->SetLabelFont(42);
   Graph_Graph37->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph37->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph37->GetYaxis()->SetTitleFont(42);
   Graph_Graph37->GetZaxis()->SetLabelFont(42);
   Graph_Graph37->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph37->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph37->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph37);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx38[4] = {
   2.273721,
   3.57299,
   3.248172,
   2.598538};
   Double_t Graph_fy38[4] = {
   -6.1886,
   -6.1886,
   -5.626,
   -5.626};
   graph = new TGraph(4,Graph_fx38,Graph_fy38);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph38 = new TH1F("Graph_Graph38","Graph",100,2.143794,3.702917);
   Graph_Graph38->SetMinimum(-6.24486);
   Graph_Graph38->SetMaximum(-5.56974);
   Graph_Graph38->SetDirectory(0);
   Graph_Graph38->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph38->SetLineColor(ci);
   Graph_Graph38->GetXaxis()->SetLabelFont(42);
   Graph_Graph38->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph38->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph38->GetXaxis()->SetTitleFont(42);
   Graph_Graph38->GetYaxis()->SetLabelFont(42);
   Graph_Graph38->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph38->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph38->GetYaxis()->SetTitleFont(42);
   Graph_Graph38->GetZaxis()->SetLabelFont(42);
   Graph_Graph38->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph38->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph38->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph38);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx39[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy39[6] = {
   5.626,
   5.0634,
   5.0634,
   5.626,
   6.1886,
   6.1886};
   graph = new TGraph(6,Graph_fx39,Graph_fy39);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph39 = new TH1F("Graph_Graph39","Graph",100,1.169342,2.728465);
   Graph_Graph39->SetMinimum(4.95088);
   Graph_Graph39->SetMaximum(6.30112);
   Graph_Graph39->SetDirectory(0);
   Graph_Graph39->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph39->SetLineColor(ci);
   Graph_Graph39->GetXaxis()->SetLabelFont(42);
   Graph_Graph39->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph39->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph39->GetXaxis()->SetTitleFont(42);
   Graph_Graph39->GetYaxis()->SetLabelFont(42);
   Graph_Graph39->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph39->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph39->GetYaxis()->SetTitleFont(42);
   Graph_Graph39->GetZaxis()->SetLabelFont(42);
   Graph_Graph39->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph39->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph39->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph39);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx40[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy40[6] = {
   4.5008,
   3.9382,
   3.9382,
   4.5008,
   5.0634,
   5.0634};
   graph = new TGraph(6,Graph_fx40,Graph_fy40);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph40 = new TH1F("Graph_Graph40","Graph",100,1.169342,2.728465);
   Graph_Graph40->SetMinimum(3.82568);
   Graph_Graph40->SetMaximum(5.17592);
   Graph_Graph40->SetDirectory(0);
   Graph_Graph40->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph40->SetLineColor(ci);
   Graph_Graph40->GetXaxis()->SetLabelFont(42);
   Graph_Graph40->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph40->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph40->GetXaxis()->SetTitleFont(42);
   Graph_Graph40->GetYaxis()->SetLabelFont(42);
   Graph_Graph40->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph40->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph40->GetYaxis()->SetTitleFont(42);
   Graph_Graph40->GetZaxis()->SetLabelFont(42);
   Graph_Graph40->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph40->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph40->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph40);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx41[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy41[6] = {
   3.3756,
   2.813,
   2.813,
   3.3756,
   3.9382,
   3.9382};
   graph = new TGraph(6,Graph_fx41,Graph_fy41);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph41 = new TH1F("Graph_Graph41","Graph",100,1.169342,2.728465);
   Graph_Graph41->SetMinimum(2.70048);
   Graph_Graph41->SetMaximum(4.05072);
   Graph_Graph41->SetDirectory(0);
   Graph_Graph41->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph41->SetLineColor(ci);
   Graph_Graph41->GetXaxis()->SetLabelFont(42);
   Graph_Graph41->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph41->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph41->GetXaxis()->SetTitleFont(42);
   Graph_Graph41->GetYaxis()->SetLabelFont(42);
   Graph_Graph41->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph41->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph41->GetYaxis()->SetTitleFont(42);
   Graph_Graph41->GetZaxis()->SetLabelFont(42);
   Graph_Graph41->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph41->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph41->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph41);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx42[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy42[6] = {
   2.2504,
   1.6878,
   1.6878,
   2.2504,
   2.813,
   2.813};
   graph = new TGraph(6,Graph_fx42,Graph_fy42);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph42 = new TH1F("Graph_Graph42","Graph",100,1.169342,2.728465);
   Graph_Graph42->SetMinimum(1.57528);
   Graph_Graph42->SetMaximum(2.92552);
   Graph_Graph42->SetDirectory(0);
   Graph_Graph42->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph42->SetLineColor(ci);
   Graph_Graph42->GetXaxis()->SetLabelFont(42);
   Graph_Graph42->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph42->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph42->GetXaxis()->SetTitleFont(42);
   Graph_Graph42->GetYaxis()->SetLabelFont(42);
   Graph_Graph42->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph42->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph42->GetYaxis()->SetTitleFont(42);
   Graph_Graph42->GetZaxis()->SetLabelFont(42);
   Graph_Graph42->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph42->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph42->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph42);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx43[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy43[6] = {
   1.1252,
   0.5626,
   0.5626,
   1.1252,
   1.6878,
   1.6878};
   graph = new TGraph(6,Graph_fx43,Graph_fy43);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph43 = new TH1F("Graph_Graph43","Graph",100,1.169342,2.728465);
   Graph_Graph43->SetMinimum(0.45008);
   Graph_Graph43->SetMaximum(1.80032);
   Graph_Graph43->SetDirectory(0);
   Graph_Graph43->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph43->SetLineColor(ci);
   Graph_Graph43->GetXaxis()->SetLabelFont(42);
   Graph_Graph43->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph43->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph43->GetXaxis()->SetTitleFont(42);
   Graph_Graph43->GetYaxis()->SetLabelFont(42);
   Graph_Graph43->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph43->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph43->GetYaxis()->SetTitleFont(42);
   Graph_Graph43->GetZaxis()->SetLabelFont(42);
   Graph_Graph43->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph43->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph43->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph43);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx44[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy44[6] = {
   -2.332053e-09,
   -0.5626,
   -0.5626,
   -4.664107e-09,
   0.5626,
   0.5626};
   graph = new TGraph(6,Graph_fx44,Graph_fy44);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph44 = new TH1F("Graph_Graph44","Graph",100,1.169342,2.728465);
   Graph_Graph44->SetMinimum(-0.67512);
   Graph_Graph44->SetMaximum(0.67512);
   Graph_Graph44->SetDirectory(0);
   Graph_Graph44->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph44->SetLineColor(ci);
   Graph_Graph44->GetXaxis()->SetLabelFont(42);
   Graph_Graph44->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph44->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph44->GetXaxis()->SetTitleFont(42);
   Graph_Graph44->GetYaxis()->SetLabelFont(42);
   Graph_Graph44->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph44->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph44->GetYaxis()->SetTitleFont(42);
   Graph_Graph44->GetZaxis()->SetLabelFont(42);
   Graph_Graph44->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph44->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph44->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph44);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx45[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy45[6] = {
   -1.1252,
   -1.6878,
   -1.6878,
   -1.1252,
   -0.5626,
   -0.5626};
   graph = new TGraph(6,Graph_fx45,Graph_fy45);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph45 = new TH1F("Graph_Graph45","Graph",100,1.169342,2.728465);
   Graph_Graph45->SetMinimum(-1.80032);
   Graph_Graph45->SetMaximum(-0.45008);
   Graph_Graph45->SetDirectory(0);
   Graph_Graph45->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph45->SetLineColor(ci);
   Graph_Graph45->GetXaxis()->SetLabelFont(42);
   Graph_Graph45->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph45->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph45->GetXaxis()->SetTitleFont(42);
   Graph_Graph45->GetYaxis()->SetLabelFont(42);
   Graph_Graph45->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph45->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph45->GetYaxis()->SetTitleFont(42);
   Graph_Graph45->GetZaxis()->SetLabelFont(42);
   Graph_Graph45->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph45->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph45->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph45);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx46[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy46[6] = {
   -2.2504,
   -2.813,
   -2.813,
   -2.2504,
   -1.6878,
   -1.6878};
   graph = new TGraph(6,Graph_fx46,Graph_fy46);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph46 = new TH1F("Graph_Graph46","Graph",100,1.169342,2.728465);
   Graph_Graph46->SetMinimum(-2.92552);
   Graph_Graph46->SetMaximum(-1.57528);
   Graph_Graph46->SetDirectory(0);
   Graph_Graph46->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph46->SetLineColor(ci);
   Graph_Graph46->GetXaxis()->SetLabelFont(42);
   Graph_Graph46->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph46->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph46->GetXaxis()->SetTitleFont(42);
   Graph_Graph46->GetYaxis()->SetLabelFont(42);
   Graph_Graph46->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph46->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph46->GetYaxis()->SetTitleFont(42);
   Graph_Graph46->GetZaxis()->SetLabelFont(42);
   Graph_Graph46->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph46->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph46->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph46);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx47[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy47[6] = {
   -3.3756,
   -3.9382,
   -3.9382,
   -3.3756,
   -2.813,
   -2.813};
   graph = new TGraph(6,Graph_fx47,Graph_fy47);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph47 = new TH1F("Graph_Graph47","Graph",100,1.169342,2.728465);
   Graph_Graph47->SetMinimum(-4.05072);
   Graph_Graph47->SetMaximum(-2.70048);
   Graph_Graph47->SetDirectory(0);
   Graph_Graph47->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph47->SetLineColor(ci);
   Graph_Graph47->GetXaxis()->SetLabelFont(42);
   Graph_Graph47->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph47->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph47->GetXaxis()->SetTitleFont(42);
   Graph_Graph47->GetYaxis()->SetLabelFont(42);
   Graph_Graph47->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph47->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph47->GetYaxis()->SetTitleFont(42);
   Graph_Graph47->GetZaxis()->SetLabelFont(42);
   Graph_Graph47->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph47->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph47->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph47);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx48[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy48[6] = {
   -4.5008,
   -5.0634,
   -5.0634,
   -4.5008,
   -3.9382,
   -3.9382};
   graph = new TGraph(6,Graph_fx48,Graph_fy48);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph48 = new TH1F("Graph_Graph48","Graph",100,1.169342,2.728465);
   Graph_Graph48->SetMinimum(-5.17592);
   Graph_Graph48->SetMaximum(-3.82568);
   Graph_Graph48->SetDirectory(0);
   Graph_Graph48->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph48->SetLineColor(ci);
   Graph_Graph48->GetXaxis()->SetLabelFont(42);
   Graph_Graph48->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph48->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph48->GetXaxis()->SetTitleFont(42);
   Graph_Graph48->GetYaxis()->SetLabelFont(42);
   Graph_Graph48->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph48->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph48->GetYaxis()->SetTitleFont(42);
   Graph_Graph48->GetZaxis()->SetLabelFont(42);
   Graph_Graph48->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph48->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph48->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph48);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx49[6] = {
   1.299269,
   1.624086,
   2.273721,
   2.598538,
   2.273721,
   1.624086};
   Double_t Graph_fy49[6] = {
   -5.626,
   -6.1886,
   -6.1886,
   -5.626,
   -5.0634,
   -5.0634};
   graph = new TGraph(6,Graph_fx49,Graph_fy49);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph49 = new TH1F("Graph_Graph49","Graph",100,1.169342,2.728465);
   Graph_Graph49->SetMinimum(-6.30112);
   Graph_Graph49->SetMaximum(-4.95088);
   Graph_Graph49->SetDirectory(0);
   Graph_Graph49->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph49->SetLineColor(ci);
   Graph_Graph49->GetXaxis()->SetLabelFont(42);
   Graph_Graph49->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph49->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph49->GetXaxis()->SetTitleFont(42);
   Graph_Graph49->GetYaxis()->SetLabelFont(42);
   Graph_Graph49->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph49->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph49->GetYaxis()->SetTitleFont(42);
   Graph_Graph49->GetZaxis()->SetLabelFont(42);
   Graph_Graph49->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph49->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph49->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph49);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx50[4] = {
   0.3248173,
   0.6496345,
   1.299269,
   1.624086};
   Double_t Graph_fy50[4] = {
   6.1886,
   5.626,
   5.626,
   6.1886};
   graph = new TGraph(4,Graph_fx50,Graph_fy50);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph50 = new TH1F("Graph_Graph50","Graph",100,0.1948904,1.754013);
   Graph_Graph50->SetMinimum(5.56974);
   Graph_Graph50->SetMaximum(6.24486);
   Graph_Graph50->SetDirectory(0);
   Graph_Graph50->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph50->SetLineColor(ci);
   Graph_Graph50->GetXaxis()->SetLabelFont(42);
   Graph_Graph50->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph50->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph50->GetXaxis()->SetTitleFont(42);
   Graph_Graph50->GetYaxis()->SetLabelFont(42);
   Graph_Graph50->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph50->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph50->GetYaxis()->SetTitleFont(42);
   Graph_Graph50->GetZaxis()->SetLabelFont(42);
   Graph_Graph50->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph50->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph50->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph50);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx51[6] = {
   0.3248173,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy51[6] = {
   5.0634,
   4.5008,
   4.5008,
   5.0634,
   5.626,
   5.626};
   graph = new TGraph(6,Graph_fx51,Graph_fy51);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph51 = new TH1F("Graph_Graph51","Graph",100,0.1948904,1.754013);
   Graph_Graph51->SetMinimum(4.38828);
   Graph_Graph51->SetMaximum(5.73852);
   Graph_Graph51->SetDirectory(0);
   Graph_Graph51->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph51->SetLineColor(ci);
   Graph_Graph51->GetXaxis()->SetLabelFont(42);
   Graph_Graph51->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph51->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph51->GetXaxis()->SetTitleFont(42);
   Graph_Graph51->GetYaxis()->SetLabelFont(42);
   Graph_Graph51->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph51->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph51->GetYaxis()->SetTitleFont(42);
   Graph_Graph51->GetZaxis()->SetLabelFont(42);
   Graph_Graph51->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph51->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph51->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph51);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx52[6] = {
   0.3248173,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy52[6] = {
   3.9382,
   3.3756,
   3.3756,
   3.9382,
   4.5008,
   4.5008};
   graph = new TGraph(6,Graph_fx52,Graph_fy52);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph52 = new TH1F("Graph_Graph52","Graph",100,0.1948904,1.754013);
   Graph_Graph52->SetMinimum(3.26308);
   Graph_Graph52->SetMaximum(4.61332);
   Graph_Graph52->SetDirectory(0);
   Graph_Graph52->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph52->SetLineColor(ci);
   Graph_Graph52->GetXaxis()->SetLabelFont(42);
   Graph_Graph52->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph52->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph52->GetXaxis()->SetTitleFont(42);
   Graph_Graph52->GetYaxis()->SetLabelFont(42);
   Graph_Graph52->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph52->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph52->GetYaxis()->SetTitleFont(42);
   Graph_Graph52->GetZaxis()->SetLabelFont(42);
   Graph_Graph52->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph52->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph52->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph52);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx53[6] = {
   0.3248173,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy53[6] = {
   2.813,
   2.2504,
   2.2504,
   2.813,
   3.3756,
   3.3756};
   graph = new TGraph(6,Graph_fx53,Graph_fy53);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph53 = new TH1F("Graph_Graph53","Graph",100,0.1948904,1.754013);
   Graph_Graph53->SetMinimum(2.13788);
   Graph_Graph53->SetMaximum(3.48812);
   Graph_Graph53->SetDirectory(0);
   Graph_Graph53->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph53->SetLineColor(ci);
   Graph_Graph53->GetXaxis()->SetLabelFont(42);
   Graph_Graph53->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph53->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph53->GetXaxis()->SetTitleFont(42);
   Graph_Graph53->GetYaxis()->SetLabelFont(42);
   Graph_Graph53->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph53->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph53->GetYaxis()->SetTitleFont(42);
   Graph_Graph53->GetZaxis()->SetLabelFont(42);
   Graph_Graph53->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph53->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph53->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph53);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx54[6] = {
   0.3248173,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy54[6] = {
   1.6878,
   1.1252,
   1.1252,
   1.6878,
   2.2504,
   2.2504};
   graph = new TGraph(6,Graph_fx54,Graph_fy54);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph54 = new TH1F("Graph_Graph54","Graph",100,0.1948904,1.754013);
   Graph_Graph54->SetMinimum(1.01268);
   Graph_Graph54->SetMaximum(2.36292);
   Graph_Graph54->SetDirectory(0);
   Graph_Graph54->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph54->SetLineColor(ci);
   Graph_Graph54->GetXaxis()->SetLabelFont(42);
   Graph_Graph54->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph54->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph54->GetXaxis()->SetTitleFont(42);
   Graph_Graph54->GetYaxis()->SetLabelFont(42);
   Graph_Graph54->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph54->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph54->GetYaxis()->SetTitleFont(42);
   Graph_Graph54->GetZaxis()->SetLabelFont(42);
   Graph_Graph54->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph54->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph54->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph54);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx55[6] = {
   0.3248173,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy55[6] = {
   0.5626,
   -1.166027e-09,
   -2.332053e-09,
   0.5626,
   1.1252,
   1.1252};
   graph = new TGraph(6,Graph_fx55,Graph_fy55);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph55 = new TH1F("Graph_Graph55","Graph",100,0.1948904,1.754013);
   Graph_Graph55->SetMinimum(-0.11252);
   Graph_Graph55->SetMaximum(1.23772);
   Graph_Graph55->SetDirectory(0);
   Graph_Graph55->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph55->SetLineColor(ci);
   Graph_Graph55->GetXaxis()->SetLabelFont(42);
   Graph_Graph55->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph55->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph55->GetXaxis()->SetTitleFont(42);
   Graph_Graph55->GetYaxis()->SetLabelFont(42);
   Graph_Graph55->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph55->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph55->GetYaxis()->SetTitleFont(42);
   Graph_Graph55->GetZaxis()->SetLabelFont(42);
   Graph_Graph55->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph55->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph55->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph55);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx56[6] = {
   0.3248172,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy56[6] = {
   -0.5626,
   -1.1252,
   -1.1252,
   -0.5626,
   -2.332053e-09,
   -1.166027e-09};
   graph = new TGraph(6,Graph_fx56,Graph_fy56);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph56 = new TH1F("Graph_Graph56","Graph",100,0.1948903,1.754013);
   Graph_Graph56->SetMinimum(-1.23772);
   Graph_Graph56->SetMaximum(0.11252);
   Graph_Graph56->SetDirectory(0);
   Graph_Graph56->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph56->SetLineColor(ci);
   Graph_Graph56->GetXaxis()->SetLabelFont(42);
   Graph_Graph56->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph56->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph56->GetXaxis()->SetTitleFont(42);
   Graph_Graph56->GetYaxis()->SetLabelFont(42);
   Graph_Graph56->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph56->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph56->GetYaxis()->SetTitleFont(42);
   Graph_Graph56->GetZaxis()->SetLabelFont(42);
   Graph_Graph56->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph56->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph56->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph56);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx57[6] = {
   0.3248172,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy57[6] = {
   -1.6878,
   -2.2504,
   -2.2504,
   -1.6878,
   -1.1252,
   -1.1252};
   graph = new TGraph(6,Graph_fx57,Graph_fy57);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph57 = new TH1F("Graph_Graph57","Graph",100,0.1948903,1.754013);
   Graph_Graph57->SetMinimum(-2.36292);
   Graph_Graph57->SetMaximum(-1.01268);
   Graph_Graph57->SetDirectory(0);
   Graph_Graph57->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph57->SetLineColor(ci);
   Graph_Graph57->GetXaxis()->SetLabelFont(42);
   Graph_Graph57->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph57->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph57->GetXaxis()->SetTitleFont(42);
   Graph_Graph57->GetYaxis()->SetLabelFont(42);
   Graph_Graph57->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph57->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph57->GetYaxis()->SetTitleFont(42);
   Graph_Graph57->GetZaxis()->SetLabelFont(42);
   Graph_Graph57->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph57->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph57->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph57);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx58[6] = {
   0.3248172,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy58[6] = {
   -2.813,
   -3.3756,
   -3.3756,
   -2.813,
   -2.2504,
   -2.2504};
   graph = new TGraph(6,Graph_fx58,Graph_fy58);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph58 = new TH1F("Graph_Graph58","Graph",100,0.1948903,1.754013);
   Graph_Graph58->SetMinimum(-3.48812);
   Graph_Graph58->SetMaximum(-2.13788);
   Graph_Graph58->SetDirectory(0);
   Graph_Graph58->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph58->SetLineColor(ci);
   Graph_Graph58->GetXaxis()->SetLabelFont(42);
   Graph_Graph58->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph58->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph58->GetXaxis()->SetTitleFont(42);
   Graph_Graph58->GetYaxis()->SetLabelFont(42);
   Graph_Graph58->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph58->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph58->GetYaxis()->SetTitleFont(42);
   Graph_Graph58->GetZaxis()->SetLabelFont(42);
   Graph_Graph58->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph58->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph58->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph58);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx59[6] = {
   0.3248172,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy59[6] = {
   -3.9382,
   -4.5008,
   -4.5008,
   -3.9382,
   -3.3756,
   -3.3756};
   graph = new TGraph(6,Graph_fx59,Graph_fy59);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph59 = new TH1F("Graph_Graph59","Graph",100,0.1948903,1.754013);
   Graph_Graph59->SetMinimum(-4.61332);
   Graph_Graph59->SetMaximum(-3.26308);
   Graph_Graph59->SetDirectory(0);
   Graph_Graph59->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph59->SetLineColor(ci);
   Graph_Graph59->GetXaxis()->SetLabelFont(42);
   Graph_Graph59->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph59->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph59->GetXaxis()->SetTitleFont(42);
   Graph_Graph59->GetYaxis()->SetLabelFont(42);
   Graph_Graph59->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph59->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph59->GetYaxis()->SetTitleFont(42);
   Graph_Graph59->GetZaxis()->SetLabelFont(42);
   Graph_Graph59->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph59->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph59->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph59);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx60[6] = {
   0.3248172,
   0.6496345,
   1.299269,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy60[6] = {
   -5.0634,
   -5.626,
   -5.626,
   -5.0634,
   -4.5008,
   -4.5008};
   graph = new TGraph(6,Graph_fx60,Graph_fy60);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph60 = new TH1F("Graph_Graph60","Graph",100,0.1948903,1.754013);
   Graph_Graph60->SetMinimum(-5.73852);
   Graph_Graph60->SetMaximum(-4.38828);
   Graph_Graph60->SetDirectory(0);
   Graph_Graph60->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph60->SetLineColor(ci);
   Graph_Graph60->GetXaxis()->SetLabelFont(42);
   Graph_Graph60->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph60->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph60->GetXaxis()->SetTitleFont(42);
   Graph_Graph60->GetYaxis()->SetLabelFont(42);
   Graph_Graph60->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph60->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph60->GetYaxis()->SetTitleFont(42);
   Graph_Graph60->GetZaxis()->SetLabelFont(42);
   Graph_Graph60->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph60->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph60->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph60);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx61[4] = {
   0.3248172,
   1.624086,
   1.299269,
   0.6496345};
   Double_t Graph_fy61[4] = {
   -6.1886,
   -6.1886,
   -5.626,
   -5.626};
   graph = new TGraph(4,Graph_fx61,Graph_fy61);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph61 = new TH1F("Graph_Graph61","Graph",100,0.1948903,1.754013);
   Graph_Graph61->SetMinimum(-6.24486);
   Graph_Graph61->SetMaximum(-5.56974);
   Graph_Graph61->SetDirectory(0);
   Graph_Graph61->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph61->SetLineColor(ci);
   Graph_Graph61->GetXaxis()->SetLabelFont(42);
   Graph_Graph61->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph61->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph61->GetXaxis()->SetTitleFont(42);
   Graph_Graph61->GetYaxis()->SetLabelFont(42);
   Graph_Graph61->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph61->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph61->GetYaxis()->SetTitleFont(42);
   Graph_Graph61->GetZaxis()->SetLabelFont(42);
   Graph_Graph61->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph61->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph61->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph61);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx62[6] = {
   -0.6496345,
   -0.3248172,
   0.3248173,
   0.6496345,
   0.3248173,
   -0.3248172};
   Double_t Graph_fy62[6] = {
   5.626,
   5.0634,
   5.0634,
   5.626,
   6.1886,
   6.1886};
   graph = new TGraph(6,Graph_fx62,Graph_fy62);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph62 = new TH1F("Graph_Graph62","Graph",100,-0.7795614,0.7795614);
   Graph_Graph62->SetMinimum(4.95088);
   Graph_Graph62->SetMaximum(6.30112);
   Graph_Graph62->SetDirectory(0);
   Graph_Graph62->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph62->SetLineColor(ci);
   Graph_Graph62->GetXaxis()->SetLabelFont(42);
   Graph_Graph62->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph62->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph62->GetXaxis()->SetTitleFont(42);
   Graph_Graph62->GetYaxis()->SetLabelFont(42);
   Graph_Graph62->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph62->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph62->GetYaxis()->SetTitleFont(42);
   Graph_Graph62->GetZaxis()->SetLabelFont(42);
   Graph_Graph62->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph62->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph62->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph62);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx63[6] = {
   -0.6496345,
   -0.3248172,
   0.3248173,
   0.6496345,
   0.3248173,
   -0.3248172};
   Double_t Graph_fy63[6] = {
   4.5008,
   3.9382,
   3.9382,
   4.5008,
   5.0634,
   5.0634};
   graph = new TGraph(6,Graph_fx63,Graph_fy63);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph63 = new TH1F("Graph_Graph63","Graph",100,-0.7795614,0.7795614);
   Graph_Graph63->SetMinimum(3.82568);
   Graph_Graph63->SetMaximum(5.17592);
   Graph_Graph63->SetDirectory(0);
   Graph_Graph63->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph63->SetLineColor(ci);
   Graph_Graph63->GetXaxis()->SetLabelFont(42);
   Graph_Graph63->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph63->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph63->GetXaxis()->SetTitleFont(42);
   Graph_Graph63->GetYaxis()->SetLabelFont(42);
   Graph_Graph63->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph63->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph63->GetYaxis()->SetTitleFont(42);
   Graph_Graph63->GetZaxis()->SetLabelFont(42);
   Graph_Graph63->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph63->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph63->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph63);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx64[6] = {
   -0.6496345,
   -0.3248172,
   0.3248173,
   0.6496345,
   0.3248173,
   -0.3248172};
   Double_t Graph_fy64[6] = {
   3.3756,
   2.813,
   2.813,
   3.3756,
   3.9382,
   3.9382};
   graph = new TGraph(6,Graph_fx64,Graph_fy64);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph64 = new TH1F("Graph_Graph64","Graph",100,-0.7795614,0.7795614);
   Graph_Graph64->SetMinimum(2.70048);
   Graph_Graph64->SetMaximum(4.05072);
   Graph_Graph64->SetDirectory(0);
   Graph_Graph64->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph64->SetLineColor(ci);
   Graph_Graph64->GetXaxis()->SetLabelFont(42);
   Graph_Graph64->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph64->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph64->GetXaxis()->SetTitleFont(42);
   Graph_Graph64->GetYaxis()->SetLabelFont(42);
   Graph_Graph64->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph64->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph64->GetYaxis()->SetTitleFont(42);
   Graph_Graph64->GetZaxis()->SetLabelFont(42);
   Graph_Graph64->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph64->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph64->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph64);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx65[6] = {
   -0.6496345,
   -0.3248172,
   0.3248173,
   0.6496345,
   0.3248173,
   -0.3248172};
   Double_t Graph_fy65[6] = {
   2.2504,
   1.6878,
   1.6878,
   2.2504,
   2.813,
   2.813};
   graph = new TGraph(6,Graph_fx65,Graph_fy65);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph65 = new TH1F("Graph_Graph65","Graph",100,-0.7795614,0.7795614);
   Graph_Graph65->SetMinimum(1.57528);
   Graph_Graph65->SetMaximum(2.92552);
   Graph_Graph65->SetDirectory(0);
   Graph_Graph65->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph65->SetLineColor(ci);
   Graph_Graph65->GetXaxis()->SetLabelFont(42);
   Graph_Graph65->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph65->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph65->GetXaxis()->SetTitleFont(42);
   Graph_Graph65->GetYaxis()->SetLabelFont(42);
   Graph_Graph65->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph65->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph65->GetYaxis()->SetTitleFont(42);
   Graph_Graph65->GetZaxis()->SetLabelFont(42);
   Graph_Graph65->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph65->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph65->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph65);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx66[6] = {
   -0.6496345,
   -0.3248172,
   0.3248173,
   0.6496345,
   0.3248173,
   -0.3248172};
   Double_t Graph_fy66[6] = {
   1.1252,
   0.5626,
   0.5626,
   1.1252,
   1.6878,
   1.6878};
   graph = new TGraph(6,Graph_fx66,Graph_fy66);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph66 = new TH1F("Graph_Graph66","Graph",100,-0.7795614,0.7795614);
   Graph_Graph66->SetMinimum(0.45008);
   Graph_Graph66->SetMaximum(1.80032);
   Graph_Graph66->SetDirectory(0);
   Graph_Graph66->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph66->SetLineColor(ci);
   Graph_Graph66->GetXaxis()->SetLabelFont(42);
   Graph_Graph66->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph66->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph66->GetXaxis()->SetTitleFont(42);
   Graph_Graph66->GetYaxis()->SetLabelFont(42);
   Graph_Graph66->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph66->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph66->GetYaxis()->SetTitleFont(42);
   Graph_Graph66->GetZaxis()->SetLabelFont(42);
   Graph_Graph66->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph66->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph66->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph66);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx67[6] = {
   -0.6496345,
   -0.3248173,
   0.3248172,
   0.6496345,
   0.3248173,
   -0.3248172};
   Double_t Graph_fy67[6] = {
   1.166027e-09,
   -0.5626,
   -0.5626,
   -1.166027e-09,
   0.5626,
   0.5626};
   graph = new TGraph(6,Graph_fx67,Graph_fy67);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#b2bc65");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph67 = new TH1F("Graph_Graph67","Graph",100,-0.7795614,0.7795614);
   Graph_Graph67->SetMinimum(-0.67512);
   Graph_Graph67->SetMaximum(0.67512);
   Graph_Graph67->SetDirectory(0);
   Graph_Graph67->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph67->SetLineColor(ci);
   Graph_Graph67->GetXaxis()->SetLabelFont(42);
   Graph_Graph67->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph67->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph67->GetXaxis()->SetTitleFont(42);
   Graph_Graph67->GetYaxis()->SetLabelFont(42);
   Graph_Graph67->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph67->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph67->GetYaxis()->SetTitleFont(42);
   Graph_Graph67->GetZaxis()->SetLabelFont(42);
   Graph_Graph67->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph67->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph67->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph67);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx68[6] = {
   -0.6496345,
   -0.3248173,
   0.3248172,
   0.6496345,
   0.3248172,
   -0.3248173};
   Double_t Graph_fy68[6] = {
   -1.1252,
   -1.6878,
   -1.6878,
   -1.1252,
   -0.5626,
   -0.5626};
   graph = new TGraph(6,Graph_fx68,Graph_fy68);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph68 = new TH1F("Graph_Graph68","Graph",100,-0.7795614,0.7795614);
   Graph_Graph68->SetMinimum(-1.80032);
   Graph_Graph68->SetMaximum(-0.45008);
   Graph_Graph68->SetDirectory(0);
   Graph_Graph68->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph68->SetLineColor(ci);
   Graph_Graph68->GetXaxis()->SetLabelFont(42);
   Graph_Graph68->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph68->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph68->GetXaxis()->SetTitleFont(42);
   Graph_Graph68->GetYaxis()->SetLabelFont(42);
   Graph_Graph68->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph68->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph68->GetYaxis()->SetTitleFont(42);
   Graph_Graph68->GetZaxis()->SetLabelFont(42);
   Graph_Graph68->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph68->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph68->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph68);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx69[6] = {
   -0.6496345,
   -0.3248173,
   0.3248172,
   0.6496345,
   0.3248172,
   -0.3248173};
   Double_t Graph_fy69[6] = {
   -2.2504,
   -2.813,
   -2.813,
   -2.2504,
   -1.6878,
   -1.6878};
   graph = new TGraph(6,Graph_fx69,Graph_fy69);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph69 = new TH1F("Graph_Graph69","Graph",100,-0.7795614,0.7795614);
   Graph_Graph69->SetMinimum(-2.92552);
   Graph_Graph69->SetMaximum(-1.57528);
   Graph_Graph69->SetDirectory(0);
   Graph_Graph69->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph69->SetLineColor(ci);
   Graph_Graph69->GetXaxis()->SetLabelFont(42);
   Graph_Graph69->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph69->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph69->GetXaxis()->SetTitleFont(42);
   Graph_Graph69->GetYaxis()->SetLabelFont(42);
   Graph_Graph69->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph69->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph69->GetYaxis()->SetTitleFont(42);
   Graph_Graph69->GetZaxis()->SetLabelFont(42);
   Graph_Graph69->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph69->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph69->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph69);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx70[6] = {
   -0.6496345,
   -0.3248173,
   0.3248172,
   0.6496345,
   0.3248172,
   -0.3248173};
   Double_t Graph_fy70[6] = {
   -3.3756,
   -3.9382,
   -3.9382,
   -3.3756,
   -2.813,
   -2.813};
   graph = new TGraph(6,Graph_fx70,Graph_fy70);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph70 = new TH1F("Graph_Graph70","Graph",100,-0.7795614,0.7795614);
   Graph_Graph70->SetMinimum(-4.05072);
   Graph_Graph70->SetMaximum(-2.70048);
   Graph_Graph70->SetDirectory(0);
   Graph_Graph70->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph70->SetLineColor(ci);
   Graph_Graph70->GetXaxis()->SetLabelFont(42);
   Graph_Graph70->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph70->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph70->GetXaxis()->SetTitleFont(42);
   Graph_Graph70->GetYaxis()->SetLabelFont(42);
   Graph_Graph70->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph70->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph70->GetYaxis()->SetTitleFont(42);
   Graph_Graph70->GetZaxis()->SetLabelFont(42);
   Graph_Graph70->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph70->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph70->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph70);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx71[6] = {
   -0.6496345,
   -0.3248173,
   0.3248172,
   0.6496345,
   0.3248172,
   -0.3248173};
   Double_t Graph_fy71[6] = {
   -4.5008,
   -5.0634,
   -5.0634,
   -4.5008,
   -3.9382,
   -3.9382};
   graph = new TGraph(6,Graph_fx71,Graph_fy71);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph71 = new TH1F("Graph_Graph71","Graph",100,-0.7795614,0.7795614);
   Graph_Graph71->SetMinimum(-5.17592);
   Graph_Graph71->SetMaximum(-3.82568);
   Graph_Graph71->SetDirectory(0);
   Graph_Graph71->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph71->SetLineColor(ci);
   Graph_Graph71->GetXaxis()->SetLabelFont(42);
   Graph_Graph71->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph71->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph71->GetXaxis()->SetTitleFont(42);
   Graph_Graph71->GetYaxis()->SetLabelFont(42);
   Graph_Graph71->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph71->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph71->GetYaxis()->SetTitleFont(42);
   Graph_Graph71->GetZaxis()->SetLabelFont(42);
   Graph_Graph71->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph71->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph71->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph71);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx72[6] = {
   -0.6496345,
   -0.3248173,
   0.3248172,
   0.6496345,
   0.3248172,
   -0.3248173};
   Double_t Graph_fy72[6] = {
   -5.626,
   -6.1886,
   -6.1886,
   -5.626,
   -5.0634,
   -5.0634};
   graph = new TGraph(6,Graph_fx72,Graph_fy72);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph72 = new TH1F("Graph_Graph72","Graph",100,-0.7795614,0.7795614);
   Graph_Graph72->SetMinimum(-6.30112);
   Graph_Graph72->SetMaximum(-4.95088);
   Graph_Graph72->SetDirectory(0);
   Graph_Graph72->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph72->SetLineColor(ci);
   Graph_Graph72->GetXaxis()->SetLabelFont(42);
   Graph_Graph72->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph72->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph72->GetXaxis()->SetTitleFont(42);
   Graph_Graph72->GetYaxis()->SetLabelFont(42);
   Graph_Graph72->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph72->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph72->GetYaxis()->SetTitleFont(42);
   Graph_Graph72->GetZaxis()->SetLabelFont(42);
   Graph_Graph72->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph72->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph72->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph72);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx73[4] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248172};
   Double_t Graph_fy73[4] = {
   6.1886,
   5.626,
   5.626,
   6.1886};
   graph = new TGraph(4,Graph_fx73,Graph_fy73);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph73 = new TH1F("Graph_Graph73","Graph",100,-1.754013,-0.1948903);
   Graph_Graph73->SetMinimum(5.56974);
   Graph_Graph73->SetMaximum(6.24486);
   Graph_Graph73->SetDirectory(0);
   Graph_Graph73->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph73->SetLineColor(ci);
   Graph_Graph73->GetXaxis()->SetLabelFont(42);
   Graph_Graph73->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph73->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph73->GetXaxis()->SetTitleFont(42);
   Graph_Graph73->GetYaxis()->SetLabelFont(42);
   Graph_Graph73->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph73->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph73->GetYaxis()->SetTitleFont(42);
   Graph_Graph73->GetZaxis()->SetLabelFont(42);
   Graph_Graph73->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph73->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph73->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph73);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx74[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248172,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy74[6] = {
   5.0634,
   4.5008,
   4.5008,
   5.0634,
   5.626,
   5.626};
   graph = new TGraph(6,Graph_fx74,Graph_fy74);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph74 = new TH1F("Graph_Graph74","Graph",100,-1.754013,-0.1948903);
   Graph_Graph74->SetMinimum(4.38828);
   Graph_Graph74->SetMaximum(5.73852);
   Graph_Graph74->SetDirectory(0);
   Graph_Graph74->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph74->SetLineColor(ci);
   Graph_Graph74->GetXaxis()->SetLabelFont(42);
   Graph_Graph74->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph74->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph74->GetXaxis()->SetTitleFont(42);
   Graph_Graph74->GetYaxis()->SetLabelFont(42);
   Graph_Graph74->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph74->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph74->GetYaxis()->SetTitleFont(42);
   Graph_Graph74->GetZaxis()->SetLabelFont(42);
   Graph_Graph74->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph74->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph74->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph74);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx75[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248172,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy75[6] = {
   3.9382,
   3.3756,
   3.3756,
   3.9382,
   4.5008,
   4.5008};
   graph = new TGraph(6,Graph_fx75,Graph_fy75);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph75 = new TH1F("Graph_Graph75","Graph",100,-1.754013,-0.1948903);
   Graph_Graph75->SetMinimum(3.26308);
   Graph_Graph75->SetMaximum(4.61332);
   Graph_Graph75->SetDirectory(0);
   Graph_Graph75->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph75->SetLineColor(ci);
   Graph_Graph75->GetXaxis()->SetLabelFont(42);
   Graph_Graph75->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph75->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph75->GetXaxis()->SetTitleFont(42);
   Graph_Graph75->GetYaxis()->SetLabelFont(42);
   Graph_Graph75->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph75->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph75->GetYaxis()->SetTitleFont(42);
   Graph_Graph75->GetZaxis()->SetLabelFont(42);
   Graph_Graph75->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph75->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph75->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph75);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx76[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248172,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy76[6] = {
   2.813,
   2.2504,
   2.2504,
   2.813,
   3.3756,
   3.3756};
   graph = new TGraph(6,Graph_fx76,Graph_fy76);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph76 = new TH1F("Graph_Graph76","Graph",100,-1.754013,-0.1948903);
   Graph_Graph76->SetMinimum(2.13788);
   Graph_Graph76->SetMaximum(3.48812);
   Graph_Graph76->SetDirectory(0);
   Graph_Graph76->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph76->SetLineColor(ci);
   Graph_Graph76->GetXaxis()->SetLabelFont(42);
   Graph_Graph76->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph76->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph76->GetXaxis()->SetTitleFont(42);
   Graph_Graph76->GetYaxis()->SetLabelFont(42);
   Graph_Graph76->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph76->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph76->GetYaxis()->SetTitleFont(42);
   Graph_Graph76->GetZaxis()->SetLabelFont(42);
   Graph_Graph76->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph76->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph76->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph76);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx77[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248172,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy77[6] = {
   1.6878,
   1.1252,
   1.1252,
   1.6878,
   2.2504,
   2.2504};
   graph = new TGraph(6,Graph_fx77,Graph_fy77);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph77 = new TH1F("Graph_Graph77","Graph",100,-1.754013,-0.1948903);
   Graph_Graph77->SetMinimum(1.01268);
   Graph_Graph77->SetMaximum(2.36292);
   Graph_Graph77->SetDirectory(0);
   Graph_Graph77->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph77->SetLineColor(ci);
   Graph_Graph77->GetXaxis()->SetLabelFont(42);
   Graph_Graph77->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph77->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph77->GetXaxis()->SetTitleFont(42);
   Graph_Graph77->GetYaxis()->SetLabelFont(42);
   Graph_Graph77->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph77->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph77->GetYaxis()->SetTitleFont(42);
   Graph_Graph77->GetZaxis()->SetLabelFont(42);
   Graph_Graph77->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph77->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph77->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph77);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx78[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248172,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy78[6] = {
   0.5626,
   2.332053e-09,
   1.166027e-09,
   0.5626,
   1.1252,
   1.1252};
   graph = new TGraph(6,Graph_fx78,Graph_fy78);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph78 = new TH1F("Graph_Graph78","Graph",100,-1.754013,-0.1948903);
   Graph_Graph78->SetMinimum(0);
   Graph_Graph78->SetMaximum(1.23772);
   Graph_Graph78->SetDirectory(0);
   Graph_Graph78->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph78->SetLineColor(ci);
   Graph_Graph78->GetXaxis()->SetLabelFont(42);
   Graph_Graph78->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph78->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph78->GetXaxis()->SetTitleFont(42);
   Graph_Graph78->GetYaxis()->SetLabelFont(42);
   Graph_Graph78->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph78->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph78->GetYaxis()->SetTitleFont(42);
   Graph_Graph78->GetZaxis()->SetLabelFont(42);
   Graph_Graph78->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph78->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph78->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph78);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx79[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248173,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy79[6] = {
   -0.5626,
   -1.1252,
   -1.1252,
   -0.5626,
   1.166027e-09,
   2.332053e-09};
   graph = new TGraph(6,Graph_fx79,Graph_fy79);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph79 = new TH1F("Graph_Graph79","Graph",100,-1.754013,-0.1948904);
   Graph_Graph79->SetMinimum(-1.23772);
   Graph_Graph79->SetMaximum(0.11252);
   Graph_Graph79->SetDirectory(0);
   Graph_Graph79->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph79->SetLineColor(ci);
   Graph_Graph79->GetXaxis()->SetLabelFont(42);
   Graph_Graph79->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph79->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph79->GetXaxis()->SetTitleFont(42);
   Graph_Graph79->GetYaxis()->SetLabelFont(42);
   Graph_Graph79->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph79->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph79->GetYaxis()->SetTitleFont(42);
   Graph_Graph79->GetZaxis()->SetLabelFont(42);
   Graph_Graph79->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph79->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph79->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph79);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx80[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248173,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy80[6] = {
   -1.6878,
   -2.2504,
   -2.2504,
   -1.6878,
   -1.1252,
   -1.1252};
   graph = new TGraph(6,Graph_fx80,Graph_fy80);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph80 = new TH1F("Graph_Graph80","Graph",100,-1.754013,-0.1948904);
   Graph_Graph80->SetMinimum(-2.36292);
   Graph_Graph80->SetMaximum(-1.01268);
   Graph_Graph80->SetDirectory(0);
   Graph_Graph80->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph80->SetLineColor(ci);
   Graph_Graph80->GetXaxis()->SetLabelFont(42);
   Graph_Graph80->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph80->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph80->GetXaxis()->SetTitleFont(42);
   Graph_Graph80->GetYaxis()->SetLabelFont(42);
   Graph_Graph80->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph80->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph80->GetYaxis()->SetTitleFont(42);
   Graph_Graph80->GetZaxis()->SetLabelFont(42);
   Graph_Graph80->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph80->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph80->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph80);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx81[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248173,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy81[6] = {
   -2.813,
   -3.3756,
   -3.3756,
   -2.813,
   -2.2504,
   -2.2504};
   graph = new TGraph(6,Graph_fx81,Graph_fy81);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph81 = new TH1F("Graph_Graph81","Graph",100,-1.754013,-0.1948904);
   Graph_Graph81->SetMinimum(-3.48812);
   Graph_Graph81->SetMaximum(-2.13788);
   Graph_Graph81->SetDirectory(0);
   Graph_Graph81->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph81->SetLineColor(ci);
   Graph_Graph81->GetXaxis()->SetLabelFont(42);
   Graph_Graph81->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph81->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph81->GetXaxis()->SetTitleFont(42);
   Graph_Graph81->GetYaxis()->SetLabelFont(42);
   Graph_Graph81->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph81->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph81->GetYaxis()->SetTitleFont(42);
   Graph_Graph81->GetZaxis()->SetLabelFont(42);
   Graph_Graph81->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph81->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph81->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph81);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx82[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248173,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy82[6] = {
   -3.9382,
   -4.5008,
   -4.5008,
   -3.9382,
   -3.3756,
   -3.3756};
   graph = new TGraph(6,Graph_fx82,Graph_fy82);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph82 = new TH1F("Graph_Graph82","Graph",100,-1.754013,-0.1948904);
   Graph_Graph82->SetMinimum(-4.61332);
   Graph_Graph82->SetMaximum(-3.26308);
   Graph_Graph82->SetDirectory(0);
   Graph_Graph82->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph82->SetLineColor(ci);
   Graph_Graph82->GetXaxis()->SetLabelFont(42);
   Graph_Graph82->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph82->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph82->GetXaxis()->SetTitleFont(42);
   Graph_Graph82->GetYaxis()->SetLabelFont(42);
   Graph_Graph82->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph82->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph82->GetYaxis()->SetTitleFont(42);
   Graph_Graph82->GetZaxis()->SetLabelFont(42);
   Graph_Graph82->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph82->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph82->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph82);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx83[6] = {
   -1.624086,
   -1.299269,
   -0.6496345,
   -0.3248173,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy83[6] = {
   -5.0634,
   -5.626,
   -5.626,
   -5.0634,
   -4.5008,
   -4.5008};
   graph = new TGraph(6,Graph_fx83,Graph_fy83);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph83 = new TH1F("Graph_Graph83","Graph",100,-1.754013,-0.1948904);
   Graph_Graph83->SetMinimum(-5.73852);
   Graph_Graph83->SetMaximum(-4.38828);
   Graph_Graph83->SetDirectory(0);
   Graph_Graph83->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph83->SetLineColor(ci);
   Graph_Graph83->GetXaxis()->SetLabelFont(42);
   Graph_Graph83->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph83->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph83->GetXaxis()->SetTitleFont(42);
   Graph_Graph83->GetYaxis()->SetLabelFont(42);
   Graph_Graph83->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph83->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph83->GetYaxis()->SetTitleFont(42);
   Graph_Graph83->GetZaxis()->SetLabelFont(42);
   Graph_Graph83->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph83->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph83->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph83);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx84[4] = {
   -1.624086,
   -0.3248173,
   -0.6496345,
   -1.299269};
   Double_t Graph_fy84[4] = {
   -6.1886,
   -6.1886,
   -5.626,
   -5.626};
   graph = new TGraph(4,Graph_fx84,Graph_fy84);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph84 = new TH1F("Graph_Graph84","Graph",100,-1.754013,-0.1948904);
   Graph_Graph84->SetMinimum(-6.24486);
   Graph_Graph84->SetMaximum(-5.56974);
   Graph_Graph84->SetDirectory(0);
   Graph_Graph84->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph84->SetLineColor(ci);
   Graph_Graph84->GetXaxis()->SetLabelFont(42);
   Graph_Graph84->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph84->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph84->GetXaxis()->SetTitleFont(42);
   Graph_Graph84->GetYaxis()->SetLabelFont(42);
   Graph_Graph84->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph84->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph84->GetYaxis()->SetTitleFont(42);
   Graph_Graph84->GetZaxis()->SetLabelFont(42);
   Graph_Graph84->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph84->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph84->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph84);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx85[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy85[6] = {
   5.626,
   5.0634,
   5.0634,
   5.626,
   6.1886,
   6.1886};
   graph = new TGraph(6,Graph_fx85,Graph_fy85);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph85 = new TH1F("Graph_Graph85","Graph",100,-2.728465,-1.169342);
   Graph_Graph85->SetMinimum(4.95088);
   Graph_Graph85->SetMaximum(6.30112);
   Graph_Graph85->SetDirectory(0);
   Graph_Graph85->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph85->SetLineColor(ci);
   Graph_Graph85->GetXaxis()->SetLabelFont(42);
   Graph_Graph85->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph85->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph85->GetXaxis()->SetTitleFont(42);
   Graph_Graph85->GetYaxis()->SetLabelFont(42);
   Graph_Graph85->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph85->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph85->GetYaxis()->SetTitleFont(42);
   Graph_Graph85->GetZaxis()->SetLabelFont(42);
   Graph_Graph85->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph85->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph85->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph85);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx86[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy86[6] = {
   4.5008,
   3.9382,
   3.9382,
   4.5008,
   5.0634,
   5.0634};
   graph = new TGraph(6,Graph_fx86,Graph_fy86);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph86 = new TH1F("Graph_Graph86","Graph",100,-2.728465,-1.169342);
   Graph_Graph86->SetMinimum(3.82568);
   Graph_Graph86->SetMaximum(5.17592);
   Graph_Graph86->SetDirectory(0);
   Graph_Graph86->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph86->SetLineColor(ci);
   Graph_Graph86->GetXaxis()->SetLabelFont(42);
   Graph_Graph86->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph86->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph86->GetXaxis()->SetTitleFont(42);
   Graph_Graph86->GetYaxis()->SetLabelFont(42);
   Graph_Graph86->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph86->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph86->GetYaxis()->SetTitleFont(42);
   Graph_Graph86->GetZaxis()->SetLabelFont(42);
   Graph_Graph86->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph86->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph86->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph86);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx87[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy87[6] = {
   3.3756,
   2.813,
   2.813,
   3.3756,
   3.9382,
   3.9382};
   graph = new TGraph(6,Graph_fx87,Graph_fy87);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph87 = new TH1F("Graph_Graph87","Graph",100,-2.728465,-1.169342);
   Graph_Graph87->SetMinimum(2.70048);
   Graph_Graph87->SetMaximum(4.05072);
   Graph_Graph87->SetDirectory(0);
   Graph_Graph87->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph87->SetLineColor(ci);
   Graph_Graph87->GetXaxis()->SetLabelFont(42);
   Graph_Graph87->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph87->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph87->GetXaxis()->SetTitleFont(42);
   Graph_Graph87->GetYaxis()->SetLabelFont(42);
   Graph_Graph87->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph87->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph87->GetYaxis()->SetTitleFont(42);
   Graph_Graph87->GetZaxis()->SetLabelFont(42);
   Graph_Graph87->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph87->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph87->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph87);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx88[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy88[6] = {
   2.2504,
   1.6878,
   1.6878,
   2.2504,
   2.813,
   2.813};
   graph = new TGraph(6,Graph_fx88,Graph_fy88);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph88 = new TH1F("Graph_Graph88","Graph",100,-2.728465,-1.169342);
   Graph_Graph88->SetMinimum(1.57528);
   Graph_Graph88->SetMaximum(2.92552);
   Graph_Graph88->SetDirectory(0);
   Graph_Graph88->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph88->SetLineColor(ci);
   Graph_Graph88->GetXaxis()->SetLabelFont(42);
   Graph_Graph88->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph88->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph88->GetXaxis()->SetTitleFont(42);
   Graph_Graph88->GetYaxis()->SetLabelFont(42);
   Graph_Graph88->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph88->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph88->GetYaxis()->SetTitleFont(42);
   Graph_Graph88->GetZaxis()->SetLabelFont(42);
   Graph_Graph88->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph88->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph88->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph88);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx89[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy89[6] = {
   1.1252,
   0.5626,
   0.5626,
   1.1252,
   1.6878,
   1.6878};
   graph = new TGraph(6,Graph_fx89,Graph_fy89);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph89 = new TH1F("Graph_Graph89","Graph",100,-2.728465,-1.169342);
   Graph_Graph89->SetMinimum(0.45008);
   Graph_Graph89->SetMaximum(1.80032);
   Graph_Graph89->SetDirectory(0);
   Graph_Graph89->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph89->SetLineColor(ci);
   Graph_Graph89->GetXaxis()->SetLabelFont(42);
   Graph_Graph89->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph89->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph89->GetXaxis()->SetTitleFont(42);
   Graph_Graph89->GetYaxis()->SetLabelFont(42);
   Graph_Graph89->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph89->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph89->GetYaxis()->SetTitleFont(42);
   Graph_Graph89->GetZaxis()->SetLabelFont(42);
   Graph_Graph89->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph89->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph89->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph89);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx90[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy90[6] = {
   4.664107e-09,
   -0.5626,
   -0.5626,
   2.332053e-09,
   0.5626,
   0.5626};
   graph = new TGraph(6,Graph_fx90,Graph_fy90);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph90 = new TH1F("Graph_Graph90","Graph",100,-2.728465,-1.169342);
   Graph_Graph90->SetMinimum(-0.67512);
   Graph_Graph90->SetMaximum(0.67512);
   Graph_Graph90->SetDirectory(0);
   Graph_Graph90->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph90->SetLineColor(ci);
   Graph_Graph90->GetXaxis()->SetLabelFont(42);
   Graph_Graph90->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph90->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph90->GetXaxis()->SetTitleFont(42);
   Graph_Graph90->GetYaxis()->SetLabelFont(42);
   Graph_Graph90->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph90->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph90->GetYaxis()->SetTitleFont(42);
   Graph_Graph90->GetZaxis()->SetLabelFont(42);
   Graph_Graph90->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph90->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph90->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph90);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx91[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy91[6] = {
   -1.1252,
   -1.6878,
   -1.6878,
   -1.1252,
   -0.5626,
   -0.5626};
   graph = new TGraph(6,Graph_fx91,Graph_fy91);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph91 = new TH1F("Graph_Graph91","Graph",100,-2.728465,-1.169342);
   Graph_Graph91->SetMinimum(-1.80032);
   Graph_Graph91->SetMaximum(-0.45008);
   Graph_Graph91->SetDirectory(0);
   Graph_Graph91->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph91->SetLineColor(ci);
   Graph_Graph91->GetXaxis()->SetLabelFont(42);
   Graph_Graph91->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph91->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph91->GetXaxis()->SetTitleFont(42);
   Graph_Graph91->GetYaxis()->SetLabelFont(42);
   Graph_Graph91->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph91->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph91->GetYaxis()->SetTitleFont(42);
   Graph_Graph91->GetZaxis()->SetLabelFont(42);
   Graph_Graph91->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph91->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph91->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph91);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx92[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy92[6] = {
   -2.2504,
   -2.813,
   -2.813,
   -2.2504,
   -1.6878,
   -1.6878};
   graph = new TGraph(6,Graph_fx92,Graph_fy92);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph92 = new TH1F("Graph_Graph92","Graph",100,-2.728465,-1.169342);
   Graph_Graph92->SetMinimum(-2.92552);
   Graph_Graph92->SetMaximum(-1.57528);
   Graph_Graph92->SetDirectory(0);
   Graph_Graph92->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph92->SetLineColor(ci);
   Graph_Graph92->GetXaxis()->SetLabelFont(42);
   Graph_Graph92->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph92->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph92->GetXaxis()->SetTitleFont(42);
   Graph_Graph92->GetYaxis()->SetLabelFont(42);
   Graph_Graph92->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph92->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph92->GetYaxis()->SetTitleFont(42);
   Graph_Graph92->GetZaxis()->SetLabelFont(42);
   Graph_Graph92->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph92->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph92->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph92);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx93[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy93[6] = {
   -3.3756,
   -3.9382,
   -3.9382,
   -3.3756,
   -2.813,
   -2.813};
   graph = new TGraph(6,Graph_fx93,Graph_fy93);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph93 = new TH1F("Graph_Graph93","Graph",100,-2.728465,-1.169342);
   Graph_Graph93->SetMinimum(-4.05072);
   Graph_Graph93->SetMaximum(-2.70048);
   Graph_Graph93->SetDirectory(0);
   Graph_Graph93->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph93->SetLineColor(ci);
   Graph_Graph93->GetXaxis()->SetLabelFont(42);
   Graph_Graph93->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph93->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph93->GetXaxis()->SetTitleFont(42);
   Graph_Graph93->GetYaxis()->SetLabelFont(42);
   Graph_Graph93->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph93->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph93->GetYaxis()->SetTitleFont(42);
   Graph_Graph93->GetZaxis()->SetLabelFont(42);
   Graph_Graph93->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph93->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph93->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph93);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx94[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy94[6] = {
   -4.5008,
   -5.0634,
   -5.0634,
   -4.5008,
   -3.9382,
   -3.9382};
   graph = new TGraph(6,Graph_fx94,Graph_fy94);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph94 = new TH1F("Graph_Graph94","Graph",100,-2.728465,-1.169342);
   Graph_Graph94->SetMinimum(-5.17592);
   Graph_Graph94->SetMaximum(-3.82568);
   Graph_Graph94->SetDirectory(0);
   Graph_Graph94->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph94->SetLineColor(ci);
   Graph_Graph94->GetXaxis()->SetLabelFont(42);
   Graph_Graph94->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph94->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph94->GetXaxis()->SetTitleFont(42);
   Graph_Graph94->GetYaxis()->SetLabelFont(42);
   Graph_Graph94->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph94->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph94->GetYaxis()->SetTitleFont(42);
   Graph_Graph94->GetZaxis()->SetLabelFont(42);
   Graph_Graph94->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph94->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph94->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph94);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx95[6] = {
   -2.598538,
   -2.273721,
   -1.624086,
   -1.299269,
   -1.624086,
   -2.273721};
   Double_t Graph_fy95[6] = {
   -5.626,
   -6.1886,
   -6.1886,
   -5.626,
   -5.0634,
   -5.0634};
   graph = new TGraph(6,Graph_fx95,Graph_fy95);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph95 = new TH1F("Graph_Graph95","Graph",100,-2.728465,-1.169342);
   Graph_Graph95->SetMinimum(-6.30112);
   Graph_Graph95->SetMaximum(-4.95088);
   Graph_Graph95->SetDirectory(0);
   Graph_Graph95->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph95->SetLineColor(ci);
   Graph_Graph95->GetXaxis()->SetLabelFont(42);
   Graph_Graph95->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph95->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph95->GetXaxis()->SetTitleFont(42);
   Graph_Graph95->GetYaxis()->SetLabelFont(42);
   Graph_Graph95->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph95->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph95->GetYaxis()->SetTitleFont(42);
   Graph_Graph95->GetZaxis()->SetLabelFont(42);
   Graph_Graph95->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph95->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph95->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph95);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx96[4] = {
   -3.57299,
   -3.248172,
   -2.598538,
   -2.273721};
   Double_t Graph_fy96[4] = {
   6.1886,
   5.626,
   5.626,
   6.1886};
   graph = new TGraph(4,Graph_fx96,Graph_fy96);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#f9f90e");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph96 = new TH1F("Graph_Graph96","Graph",100,-3.702917,-2.143794);
   Graph_Graph96->SetMinimum(5.56974);
   Graph_Graph96->SetMaximum(6.24486);
   Graph_Graph96->SetDirectory(0);
   Graph_Graph96->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph96->SetLineColor(ci);
   Graph_Graph96->GetXaxis()->SetLabelFont(42);
   Graph_Graph96->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph96->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph96->GetXaxis()->SetTitleFont(42);
   Graph_Graph96->GetYaxis()->SetLabelFont(42);
   Graph_Graph96->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph96->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph96->GetYaxis()->SetTitleFont(42);
   Graph_Graph96->GetZaxis()->SetLabelFont(42);
   Graph_Graph96->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph96->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph96->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph96);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx97[6] = {
   -3.57299,
   -3.248172,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248172};
   Double_t Graph_fy97[6] = {
   5.0634,
   4.5008,
   4.5008,
   5.0634,
   5.626,
   5.626};
   graph = new TGraph(6,Graph_fx97,Graph_fy97);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph97 = new TH1F("Graph_Graph97","Graph",100,-3.702917,-2.143794);
   Graph_Graph97->SetMinimum(4.38828);
   Graph_Graph97->SetMaximum(5.73852);
   Graph_Graph97->SetDirectory(0);
   Graph_Graph97->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph97->SetLineColor(ci);
   Graph_Graph97->GetXaxis()->SetLabelFont(42);
   Graph_Graph97->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph97->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph97->GetXaxis()->SetTitleFont(42);
   Graph_Graph97->GetYaxis()->SetLabelFont(42);
   Graph_Graph97->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph97->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph97->GetYaxis()->SetTitleFont(42);
   Graph_Graph97->GetZaxis()->SetLabelFont(42);
   Graph_Graph97->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph97->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph97->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph97);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx98[6] = {
   -3.57299,
   -3.248172,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248172};
   Double_t Graph_fy98[6] = {
   3.9382,
   3.3756,
   3.3756,
   3.9382,
   4.5008,
   4.5008};
   graph = new TGraph(6,Graph_fx98,Graph_fy98);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph98 = new TH1F("Graph_Graph98","Graph",100,-3.702917,-2.143794);
   Graph_Graph98->SetMinimum(3.26308);
   Graph_Graph98->SetMaximum(4.61332);
   Graph_Graph98->SetDirectory(0);
   Graph_Graph98->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph98->SetLineColor(ci);
   Graph_Graph98->GetXaxis()->SetLabelFont(42);
   Graph_Graph98->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph98->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph98->GetXaxis()->SetTitleFont(42);
   Graph_Graph98->GetYaxis()->SetLabelFont(42);
   Graph_Graph98->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph98->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph98->GetYaxis()->SetTitleFont(42);
   Graph_Graph98->GetZaxis()->SetLabelFont(42);
   Graph_Graph98->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph98->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph98->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph98);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx99[6] = {
   -3.57299,
   -3.248172,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248172};
   Double_t Graph_fy99[6] = {
   2.813,
   2.2504,
   2.2504,
   2.813,
   3.3756,
   3.3756};
   graph = new TGraph(6,Graph_fx99,Graph_fy99);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph99 = new TH1F("Graph_Graph99","Graph",100,-3.702917,-2.143794);
   Graph_Graph99->SetMinimum(2.13788);
   Graph_Graph99->SetMaximum(3.48812);
   Graph_Graph99->SetDirectory(0);
   Graph_Graph99->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph99->SetLineColor(ci);
   Graph_Graph99->GetXaxis()->SetLabelFont(42);
   Graph_Graph99->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph99->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph99->GetXaxis()->SetTitleFont(42);
   Graph_Graph99->GetYaxis()->SetLabelFont(42);
   Graph_Graph99->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph99->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph99->GetYaxis()->SetTitleFont(42);
   Graph_Graph99->GetZaxis()->SetLabelFont(42);
   Graph_Graph99->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph99->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph99->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph99);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx100[6] = {
   -3.57299,
   -3.248172,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248172};
   Double_t Graph_fy100[6] = {
   1.6878,
   1.1252,
   1.1252,
   1.6878,
   2.2504,
   2.2504};
   graph = new TGraph(6,Graph_fx100,Graph_fy100);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph100 = new TH1F("Graph_Graph100","Graph",100,-3.702917,-2.143794);
   Graph_Graph100->SetMinimum(1.01268);
   Graph_Graph100->SetMaximum(2.36292);
   Graph_Graph100->SetDirectory(0);
   Graph_Graph100->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph100->SetLineColor(ci);
   Graph_Graph100->GetXaxis()->SetLabelFont(42);
   Graph_Graph100->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph100->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph100->GetXaxis()->SetTitleFont(42);
   Graph_Graph100->GetYaxis()->SetLabelFont(42);
   Graph_Graph100->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph100->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph100->GetYaxis()->SetTitleFont(42);
   Graph_Graph100->GetZaxis()->SetLabelFont(42);
   Graph_Graph100->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph100->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph100->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph100);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx101[6] = {
   -3.57299,
   -3.248173,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248172};
   Double_t Graph_fy101[6] = {
   0.5626,
   5.830134e-09,
   4.664107e-09,
   0.5626,
   1.1252,
   1.1252};
   graph = new TGraph(6,Graph_fx101,Graph_fy101);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph101 = new TH1F("Graph_Graph101","Graph",100,-3.702917,-2.143794);
   Graph_Graph101->SetMinimum(0);
   Graph_Graph101->SetMaximum(1.23772);
   Graph_Graph101->SetDirectory(0);
   Graph_Graph101->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph101->SetLineColor(ci);
   Graph_Graph101->GetXaxis()->SetLabelFont(42);
   Graph_Graph101->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph101->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph101->GetXaxis()->SetTitleFont(42);
   Graph_Graph101->GetYaxis()->SetLabelFont(42);
   Graph_Graph101->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph101->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph101->GetYaxis()->SetTitleFont(42);
   Graph_Graph101->GetZaxis()->SetLabelFont(42);
   Graph_Graph101->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph101->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph101->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph101);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx102[6] = {
   -3.57299,
   -3.248173,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248173};
   Double_t Graph_fy102[6] = {
   -0.5626,
   -1.1252,
   -1.1252,
   -0.5626,
   4.664107e-09,
   5.830134e-09};
   graph = new TGraph(6,Graph_fx102,Graph_fy102);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph102 = new TH1F("Graph_Graph102","Graph",100,-3.702917,-2.143794);
   Graph_Graph102->SetMinimum(-1.23772);
   Graph_Graph102->SetMaximum(0.11252);
   Graph_Graph102->SetDirectory(0);
   Graph_Graph102->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph102->SetLineColor(ci);
   Graph_Graph102->GetXaxis()->SetLabelFont(42);
   Graph_Graph102->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph102->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph102->GetXaxis()->SetTitleFont(42);
   Graph_Graph102->GetYaxis()->SetLabelFont(42);
   Graph_Graph102->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph102->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph102->GetYaxis()->SetTitleFont(42);
   Graph_Graph102->GetZaxis()->SetLabelFont(42);
   Graph_Graph102->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph102->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph102->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph102);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx103[6] = {
   -3.57299,
   -3.248173,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248173};
   Double_t Graph_fy103[6] = {
   -1.6878,
   -2.2504,
   -2.2504,
   -1.6878,
   -1.1252,
   -1.1252};
   graph = new TGraph(6,Graph_fx103,Graph_fy103);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph103 = new TH1F("Graph_Graph103","Graph",100,-3.702917,-2.143794);
   Graph_Graph103->SetMinimum(-2.36292);
   Graph_Graph103->SetMaximum(-1.01268);
   Graph_Graph103->SetDirectory(0);
   Graph_Graph103->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph103->SetLineColor(ci);
   Graph_Graph103->GetXaxis()->SetLabelFont(42);
   Graph_Graph103->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph103->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph103->GetXaxis()->SetTitleFont(42);
   Graph_Graph103->GetYaxis()->SetLabelFont(42);
   Graph_Graph103->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph103->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph103->GetYaxis()->SetTitleFont(42);
   Graph_Graph103->GetZaxis()->SetLabelFont(42);
   Graph_Graph103->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph103->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph103->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph103);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx104[6] = {
   -3.57299,
   -3.248173,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248173};
   Double_t Graph_fy104[6] = {
   -2.813,
   -3.3756,
   -3.3756,
   -2.813,
   -2.2504,
   -2.2504};
   graph = new TGraph(6,Graph_fx104,Graph_fy104);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph104 = new TH1F("Graph_Graph104","Graph",100,-3.702917,-2.143794);
   Graph_Graph104->SetMinimum(-3.48812);
   Graph_Graph104->SetMaximum(-2.13788);
   Graph_Graph104->SetDirectory(0);
   Graph_Graph104->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph104->SetLineColor(ci);
   Graph_Graph104->GetXaxis()->SetLabelFont(42);
   Graph_Graph104->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph104->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph104->GetXaxis()->SetTitleFont(42);
   Graph_Graph104->GetYaxis()->SetLabelFont(42);
   Graph_Graph104->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph104->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph104->GetYaxis()->SetTitleFont(42);
   Graph_Graph104->GetZaxis()->SetLabelFont(42);
   Graph_Graph104->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph104->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph104->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph104);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx105[6] = {
   -3.57299,
   -3.248173,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248173};
   Double_t Graph_fy105[6] = {
   -3.9382,
   -4.5008,
   -4.5008,
   -3.9382,
   -3.3756,
   -3.3756};
   graph = new TGraph(6,Graph_fx105,Graph_fy105);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph105 = new TH1F("Graph_Graph105","Graph",100,-3.702917,-2.143794);
   Graph_Graph105->SetMinimum(-4.61332);
   Graph_Graph105->SetMaximum(-3.26308);
   Graph_Graph105->SetDirectory(0);
   Graph_Graph105->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph105->SetLineColor(ci);
   Graph_Graph105->GetXaxis()->SetLabelFont(42);
   Graph_Graph105->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph105->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph105->GetXaxis()->SetTitleFont(42);
   Graph_Graph105->GetYaxis()->SetLabelFont(42);
   Graph_Graph105->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph105->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph105->GetYaxis()->SetTitleFont(42);
   Graph_Graph105->GetZaxis()->SetLabelFont(42);
   Graph_Graph105->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph105->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph105->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph105);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx106[6] = {
   -3.57299,
   -3.248173,
   -2.598538,
   -2.273721,
   -2.598538,
   -3.248173};
   Double_t Graph_fy106[6] = {
   -5.0634,
   -5.626,
   -5.626,
   -5.0634,
   -4.5008,
   -4.5008};
   graph = new TGraph(6,Graph_fx106,Graph_fy106);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph106 = new TH1F("Graph_Graph106","Graph",100,-3.702917,-2.143794);
   Graph_Graph106->SetMinimum(-5.73852);
   Graph_Graph106->SetMaximum(-4.38828);
   Graph_Graph106->SetDirectory(0);
   Graph_Graph106->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph106->SetLineColor(ci);
   Graph_Graph106->GetXaxis()->SetLabelFont(42);
   Graph_Graph106->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph106->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph106->GetXaxis()->SetTitleFont(42);
   Graph_Graph106->GetYaxis()->SetLabelFont(42);
   Graph_Graph106->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph106->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph106->GetYaxis()->SetTitleFont(42);
   Graph_Graph106->GetZaxis()->SetLabelFont(42);
   Graph_Graph106->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph106->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph106->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph106);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx107[4] = {
   -3.57299,
   -2.273721,
   -2.598538,
   -3.248173};
   Double_t Graph_fy107[4] = {
   -6.1886,
   -6.1886,
   -5.626,
   -5.626};
   graph = new TGraph(4,Graph_fx107,Graph_fy107);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph107 = new TH1F("Graph_Graph107","Graph",100,-3.702917,-2.143794);
   Graph_Graph107->SetMinimum(-6.24486);
   Graph_Graph107->SetMaximum(-5.56974);
   Graph_Graph107->SetDirectory(0);
   Graph_Graph107->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph107->SetLineColor(ci);
   Graph_Graph107->GetXaxis()->SetLabelFont(42);
   Graph_Graph107->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph107->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph107->GetXaxis()->SetTitleFont(42);
   Graph_Graph107->GetYaxis()->SetLabelFont(42);
   Graph_Graph107->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph107->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph107->GetYaxis()->SetTitleFont(42);
   Graph_Graph107->GetZaxis()->SetLabelFont(42);
   Graph_Graph107->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph107->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph107->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph107);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx108[4] = {
   -4.222624,
   -3.57299,
   -3.248172,
   -3.57299};
   Double_t Graph_fy108[4] = {
   5.0634,
   5.0634,
   5.626,
   6.1886};
   graph = new TGraph(4,Graph_fx108,Graph_fy108);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph108 = new TH1F("Graph_Graph108","Graph",100,-4.320069,-3.150727);
   Graph_Graph108->SetMinimum(4.95088);
   Graph_Graph108->SetMaximum(6.30112);
   Graph_Graph108->SetDirectory(0);
   Graph_Graph108->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph108->SetLineColor(ci);
   Graph_Graph108->GetXaxis()->SetLabelFont(42);
   Graph_Graph108->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph108->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph108->GetXaxis()->SetTitleFont(42);
   Graph_Graph108->GetYaxis()->SetLabelFont(42);
   Graph_Graph108->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph108->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph108->GetYaxis()->SetTitleFont(42);
   Graph_Graph108->GetZaxis()->SetLabelFont(42);
   Graph_Graph108->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph108->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph108->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph108);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx109[6] = {
   -4.547441,
   -4.222624,
   -3.57299,
   -3.248172,
   -3.57299,
   -4.222624};
   Double_t Graph_fy109[6] = {
   4.5008,
   3.9382,
   3.9382,
   4.5008,
   5.0634,
   5.0634};
   graph = new TGraph(6,Graph_fx109,Graph_fy109);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph109 = new TH1F("Graph_Graph109","Graph",100,-4.677368,-3.118246);
   Graph_Graph109->SetMinimum(3.82568);
   Graph_Graph109->SetMaximum(5.17592);
   Graph_Graph109->SetDirectory(0);
   Graph_Graph109->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph109->SetLineColor(ci);
   Graph_Graph109->GetXaxis()->SetLabelFont(42);
   Graph_Graph109->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph109->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph109->GetXaxis()->SetTitleFont(42);
   Graph_Graph109->GetYaxis()->SetLabelFont(42);
   Graph_Graph109->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph109->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph109->GetYaxis()->SetTitleFont(42);
   Graph_Graph109->GetZaxis()->SetLabelFont(42);
   Graph_Graph109->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph109->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph109->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph109);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx110[6] = {
   -4.547441,
   -4.222624,
   -3.57299,
   -3.248172,
   -3.57299,
   -4.222624};
   Double_t Graph_fy110[6] = {
   3.3756,
   2.813,
   2.813,
   3.3756,
   3.9382,
   3.9382};
   graph = new TGraph(6,Graph_fx110,Graph_fy110);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph110 = new TH1F("Graph_Graph110","Graph",100,-4.677368,-3.118246);
   Graph_Graph110->SetMinimum(2.70048);
   Graph_Graph110->SetMaximum(4.05072);
   Graph_Graph110->SetDirectory(0);
   Graph_Graph110->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph110->SetLineColor(ci);
   Graph_Graph110->GetXaxis()->SetLabelFont(42);
   Graph_Graph110->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph110->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph110->GetXaxis()->SetTitleFont(42);
   Graph_Graph110->GetYaxis()->SetLabelFont(42);
   Graph_Graph110->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph110->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph110->GetYaxis()->SetTitleFont(42);
   Graph_Graph110->GetZaxis()->SetLabelFont(42);
   Graph_Graph110->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph110->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph110->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph110);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx111[6] = {
   -4.547441,
   -4.222624,
   -3.57299,
   -3.248172,
   -3.57299,
   -4.222624};
   Double_t Graph_fy111[6] = {
   2.2504,
   1.6878,
   1.6878,
   2.2504,
   2.813,
   2.813};
   graph = new TGraph(6,Graph_fx111,Graph_fy111);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph111 = new TH1F("Graph_Graph111","Graph",100,-4.677368,-3.118246);
   Graph_Graph111->SetMinimum(1.57528);
   Graph_Graph111->SetMaximum(2.92552);
   Graph_Graph111->SetDirectory(0);
   Graph_Graph111->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph111->SetLineColor(ci);
   Graph_Graph111->GetXaxis()->SetLabelFont(42);
   Graph_Graph111->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph111->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph111->GetXaxis()->SetTitleFont(42);
   Graph_Graph111->GetYaxis()->SetLabelFont(42);
   Graph_Graph111->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph111->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph111->GetYaxis()->SetTitleFont(42);
   Graph_Graph111->GetZaxis()->SetLabelFont(42);
   Graph_Graph111->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph111->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph111->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph111);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx112[6] = {
   -4.547441,
   -4.222624,
   -3.57299,
   -3.248172,
   -3.57299,
   -4.222624};
   Double_t Graph_fy112[6] = {
   1.1252,
   0.5626,
   0.5626,
   1.1252,
   1.6878,
   1.6878};
   graph = new TGraph(6,Graph_fx112,Graph_fy112);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph112 = new TH1F("Graph_Graph112","Graph",100,-4.677368,-3.118246);
   Graph_Graph112->SetMinimum(0.45008);
   Graph_Graph112->SetMaximum(1.80032);
   Graph_Graph112->SetDirectory(0);
   Graph_Graph112->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph112->SetLineColor(ci);
   Graph_Graph112->GetXaxis()->SetLabelFont(42);
   Graph_Graph112->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph112->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph112->GetXaxis()->SetTitleFont(42);
   Graph_Graph112->GetYaxis()->SetLabelFont(42);
   Graph_Graph112->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph112->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph112->GetYaxis()->SetTitleFont(42);
   Graph_Graph112->GetZaxis()->SetLabelFont(42);
   Graph_Graph112->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph112->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph112->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph112);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx113[6] = {
   -4.547442,
   -4.222624,
   -3.57299,
   -3.248173,
   -3.57299,
   -4.222624};
   Double_t Graph_fy113[6] = {
   8.162187e-09,
   -0.5626,
   -0.5626,
   5.830134e-09,
   0.5626,
   0.5626};
   graph = new TGraph(6,Graph_fx113,Graph_fy113);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph113 = new TH1F("Graph_Graph113","Graph",100,-4.677368,-3.118246);
   Graph_Graph113->SetMinimum(-0.67512);
   Graph_Graph113->SetMaximum(0.67512);
   Graph_Graph113->SetDirectory(0);
   Graph_Graph113->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph113->SetLineColor(ci);
   Graph_Graph113->GetXaxis()->SetLabelFont(42);
   Graph_Graph113->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph113->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph113->GetXaxis()->SetTitleFont(42);
   Graph_Graph113->GetYaxis()->SetLabelFont(42);
   Graph_Graph113->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph113->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph113->GetYaxis()->SetTitleFont(42);
   Graph_Graph113->GetZaxis()->SetLabelFont(42);
   Graph_Graph113->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph113->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph113->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph113);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx114[6] = {
   -4.547442,
   -4.222624,
   -3.57299,
   -3.248173,
   -3.57299,
   -4.222624};
   Double_t Graph_fy114[6] = {
   -1.1252,
   -1.6878,
   -1.6878,
   -1.1252,
   -0.5626,
   -0.5626};
   graph = new TGraph(6,Graph_fx114,Graph_fy114);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph114 = new TH1F("Graph_Graph114","Graph",100,-4.677368,-3.118246);
   Graph_Graph114->SetMinimum(-1.80032);
   Graph_Graph114->SetMaximum(-0.45008);
   Graph_Graph114->SetDirectory(0);
   Graph_Graph114->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph114->SetLineColor(ci);
   Graph_Graph114->GetXaxis()->SetLabelFont(42);
   Graph_Graph114->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph114->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph114->GetXaxis()->SetTitleFont(42);
   Graph_Graph114->GetYaxis()->SetLabelFont(42);
   Graph_Graph114->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph114->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph114->GetYaxis()->SetTitleFont(42);
   Graph_Graph114->GetZaxis()->SetLabelFont(42);
   Graph_Graph114->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph114->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph114->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph114);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx115[6] = {
   -4.547442,
   -4.222624,
   -3.57299,
   -3.248173,
   -3.57299,
   -4.222624};
   Double_t Graph_fy115[6] = {
   -2.2504,
   -2.813,
   -2.813,
   -2.2504,
   -1.6878,
   -1.6878};
   graph = new TGraph(6,Graph_fx115,Graph_fy115);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph115 = new TH1F("Graph_Graph115","Graph",100,-4.677368,-3.118246);
   Graph_Graph115->SetMinimum(-2.92552);
   Graph_Graph115->SetMaximum(-1.57528);
   Graph_Graph115->SetDirectory(0);
   Graph_Graph115->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph115->SetLineColor(ci);
   Graph_Graph115->GetXaxis()->SetLabelFont(42);
   Graph_Graph115->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph115->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph115->GetXaxis()->SetTitleFont(42);
   Graph_Graph115->GetYaxis()->SetLabelFont(42);
   Graph_Graph115->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph115->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph115->GetYaxis()->SetTitleFont(42);
   Graph_Graph115->GetZaxis()->SetLabelFont(42);
   Graph_Graph115->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph115->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph115->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph115);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx116[6] = {
   -4.547442,
   -4.222624,
   -3.57299,
   -3.248173,
   -3.57299,
   -4.222624};
   Double_t Graph_fy116[6] = {
   -3.3756,
   -3.9382,
   -3.9382,
   -3.3756,
   -2.813,
   -2.813};
   graph = new TGraph(6,Graph_fx116,Graph_fy116);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph116 = new TH1F("Graph_Graph116","Graph",100,-4.677368,-3.118246);
   Graph_Graph116->SetMinimum(-4.05072);
   Graph_Graph116->SetMaximum(-2.70048);
   Graph_Graph116->SetDirectory(0);
   Graph_Graph116->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph116->SetLineColor(ci);
   Graph_Graph116->GetXaxis()->SetLabelFont(42);
   Graph_Graph116->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph116->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph116->GetXaxis()->SetTitleFont(42);
   Graph_Graph116->GetYaxis()->SetLabelFont(42);
   Graph_Graph116->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph116->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph116->GetYaxis()->SetTitleFont(42);
   Graph_Graph116->GetZaxis()->SetLabelFont(42);
   Graph_Graph116->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph116->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph116->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph116);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx117[6] = {
   -4.547442,
   -4.222624,
   -3.57299,
   -3.248173,
   -3.57299,
   -4.222624};
   Double_t Graph_fy117[6] = {
   -4.5008,
   -5.0634,
   -5.0634,
   -4.5008,
   -3.9382,
   -3.9382};
   graph = new TGraph(6,Graph_fx117,Graph_fy117);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph117 = new TH1F("Graph_Graph117","Graph",100,-4.677368,-3.118246);
   Graph_Graph117->SetMinimum(-5.17592);
   Graph_Graph117->SetMaximum(-3.82568);
   Graph_Graph117->SetDirectory(0);
   Graph_Graph117->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph117->SetLineColor(ci);
   Graph_Graph117->GetXaxis()->SetLabelFont(42);
   Graph_Graph117->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph117->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph117->GetXaxis()->SetTitleFont(42);
   Graph_Graph117->GetYaxis()->SetLabelFont(42);
   Graph_Graph117->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph117->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph117->GetYaxis()->SetTitleFont(42);
   Graph_Graph117->GetZaxis()->SetLabelFont(42);
   Graph_Graph117->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph117->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph117->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph117);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx118[4] = {
   -3.57299,
   -3.248173,
   -3.57299,
   -4.222624};
   Double_t Graph_fy118[4] = {
   -6.1886,
   -5.626,
   -5.0634,
   -5.0634};
   graph = new TGraph(4,Graph_fx118,Graph_fy118);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph118 = new TH1F("Graph_Graph118","Graph",100,-4.320069,-3.150727);
   Graph_Graph118->SetMinimum(-6.30112);
   Graph_Graph118->SetMaximum(-4.95088);
   Graph_Graph118->SetDirectory(0);
   Graph_Graph118->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph118->SetLineColor(ci);
   Graph_Graph118->GetXaxis()->SetLabelFont(42);
   Graph_Graph118->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph118->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph118->GetXaxis()->SetTitleFont(42);
   Graph_Graph118->GetYaxis()->SetLabelFont(42);
   Graph_Graph118->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph118->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph118->GetYaxis()->SetTitleFont(42);
   Graph_Graph118->GetZaxis()->SetLabelFont(42);
   Graph_Graph118->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph118->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph118->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph118);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx119[4] = {
   -5.197076,
   -4.547441,
   -4.222624,
   -4.547441};
   Double_t Graph_fy119[4] = {
   3.3756,
   3.3756,
   3.9382,
   4.5008};
   graph = new TGraph(4,Graph_fx119,Graph_fy119);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph119 = new TH1F("Graph_Graph119","Graph",100,-5.294521,-4.125179);
   Graph_Graph119->SetMinimum(3.26308);
   Graph_Graph119->SetMaximum(4.61332);
   Graph_Graph119->SetDirectory(0);
   Graph_Graph119->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph119->SetLineColor(ci);
   Graph_Graph119->GetXaxis()->SetLabelFont(42);
   Graph_Graph119->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph119->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph119->GetXaxis()->SetTitleFont(42);
   Graph_Graph119->GetYaxis()->SetLabelFont(42);
   Graph_Graph119->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph119->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph119->GetYaxis()->SetTitleFont(42);
   Graph_Graph119->GetZaxis()->SetLabelFont(42);
   Graph_Graph119->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph119->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph119->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph119);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx120[6] = {
   -5.521893,
   -5.197076,
   -4.547441,
   -4.222624,
   -4.547441,
   -5.197076};
   Double_t Graph_fy120[6] = {
   2.813,
   2.2504,
   2.2504,
   2.813,
   3.3756,
   3.3756};
   graph = new TGraph(6,Graph_fx120,Graph_fy120);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph120 = new TH1F("Graph_Graph120","Graph",100,-5.65182,-4.092697);
   Graph_Graph120->SetMinimum(2.13788);
   Graph_Graph120->SetMaximum(3.48812);
   Graph_Graph120->SetDirectory(0);
   Graph_Graph120->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph120->SetLineColor(ci);
   Graph_Graph120->GetXaxis()->SetLabelFont(42);
   Graph_Graph120->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph120->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph120->GetXaxis()->SetTitleFont(42);
   Graph_Graph120->GetYaxis()->SetLabelFont(42);
   Graph_Graph120->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph120->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph120->GetYaxis()->SetTitleFont(42);
   Graph_Graph120->GetZaxis()->SetLabelFont(42);
   Graph_Graph120->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph120->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph120->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph120);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx121[6] = {
   -5.521893,
   -5.197076,
   -4.547441,
   -4.222624,
   -4.547441,
   -5.197076};
   Double_t Graph_fy121[6] = {
   1.6878,
   1.1252,
   1.1252,
   1.6878,
   2.2504,
   2.2504};
   graph = new TGraph(6,Graph_fx121,Graph_fy121);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph121 = new TH1F("Graph_Graph121","Graph",100,-5.65182,-4.092697);
   Graph_Graph121->SetMinimum(1.01268);
   Graph_Graph121->SetMaximum(2.36292);
   Graph_Graph121->SetDirectory(0);
   Graph_Graph121->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph121->SetLineColor(ci);
   Graph_Graph121->GetXaxis()->SetLabelFont(42);
   Graph_Graph121->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph121->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph121->GetXaxis()->SetTitleFont(42);
   Graph_Graph121->GetYaxis()->SetLabelFont(42);
   Graph_Graph121->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph121->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph121->GetYaxis()->SetTitleFont(42);
   Graph_Graph121->GetZaxis()->SetLabelFont(42);
   Graph_Graph121->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph121->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph121->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph121);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx122[6] = {
   -5.521893,
   -5.197076,
   -4.547442,
   -4.222624,
   -4.547441,
   -5.197076};
   Double_t Graph_fy122[6] = {
   0.5626,
   9.328214e-09,
   8.162187e-09,
   0.5626,
   1.1252,
   1.1252};
   graph = new TGraph(6,Graph_fx122,Graph_fy122);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph122 = new TH1F("Graph_Graph122","Graph",100,-5.65182,-4.092697);
   Graph_Graph122->SetMinimum(0);
   Graph_Graph122->SetMaximum(1.23772);
   Graph_Graph122->SetDirectory(0);
   Graph_Graph122->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph122->SetLineColor(ci);
   Graph_Graph122->GetXaxis()->SetLabelFont(42);
   Graph_Graph122->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph122->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph122->GetXaxis()->SetTitleFont(42);
   Graph_Graph122->GetYaxis()->SetLabelFont(42);
   Graph_Graph122->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph122->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph122->GetYaxis()->SetTitleFont(42);
   Graph_Graph122->GetZaxis()->SetLabelFont(42);
   Graph_Graph122->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph122->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph122->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph122);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx123[6] = {
   -5.521893,
   -5.197076,
   -4.547442,
   -4.222624,
   -4.547442,
   -5.197076};
   Double_t Graph_fy123[6] = {
   -0.5626,
   -1.1252,
   -1.1252,
   -0.5626,
   8.162187e-09,
   9.328214e-09};
   graph = new TGraph(6,Graph_fx123,Graph_fy123);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph123 = new TH1F("Graph_Graph123","Graph",100,-5.65182,-4.092697);
   Graph_Graph123->SetMinimum(-1.23772);
   Graph_Graph123->SetMaximum(0.11252);
   Graph_Graph123->SetDirectory(0);
   Graph_Graph123->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph123->SetLineColor(ci);
   Graph_Graph123->GetXaxis()->SetLabelFont(42);
   Graph_Graph123->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph123->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph123->GetXaxis()->SetTitleFont(42);
   Graph_Graph123->GetYaxis()->SetLabelFont(42);
   Graph_Graph123->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph123->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph123->GetYaxis()->SetTitleFont(42);
   Graph_Graph123->GetZaxis()->SetLabelFont(42);
   Graph_Graph123->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph123->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph123->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph123);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx124[6] = {
   -5.521893,
   -5.197076,
   -4.547442,
   -4.222624,
   -4.547442,
   -5.197076};
   Double_t Graph_fy124[6] = {
   -1.6878,
   -2.2504,
   -2.2504,
   -1.6878,
   -1.1252,
   -1.1252};
   graph = new TGraph(6,Graph_fx124,Graph_fy124);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph124 = new TH1F("Graph_Graph124","Graph",100,-5.65182,-4.092697);
   Graph_Graph124->SetMinimum(-2.36292);
   Graph_Graph124->SetMaximum(-1.01268);
   Graph_Graph124->SetDirectory(0);
   Graph_Graph124->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph124->SetLineColor(ci);
   Graph_Graph124->GetXaxis()->SetLabelFont(42);
   Graph_Graph124->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph124->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph124->GetXaxis()->SetTitleFont(42);
   Graph_Graph124->GetYaxis()->SetLabelFont(42);
   Graph_Graph124->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph124->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph124->GetYaxis()->SetTitleFont(42);
   Graph_Graph124->GetZaxis()->SetLabelFont(42);
   Graph_Graph124->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph124->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph124->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph124);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx125[6] = {
   -5.521893,
   -5.197076,
   -4.547442,
   -4.222624,
   -4.547442,
   -5.197076};
   Double_t Graph_fy125[6] = {
   -2.813,
   -3.3756,
   -3.3756,
   -2.813,
   -2.2504,
   -2.2504};
   graph = new TGraph(6,Graph_fx125,Graph_fy125);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph125 = new TH1F("Graph_Graph125","Graph",100,-5.65182,-4.092697);
   Graph_Graph125->SetMinimum(-3.48812);
   Graph_Graph125->SetMaximum(-2.13788);
   Graph_Graph125->SetDirectory(0);
   Graph_Graph125->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph125->SetLineColor(ci);
   Graph_Graph125->GetXaxis()->SetLabelFont(42);
   Graph_Graph125->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph125->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph125->GetXaxis()->SetTitleFont(42);
   Graph_Graph125->GetYaxis()->SetLabelFont(42);
   Graph_Graph125->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph125->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph125->GetYaxis()->SetTitleFont(42);
   Graph_Graph125->GetZaxis()->SetLabelFont(42);
   Graph_Graph125->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph125->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph125->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph125);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx126[4] = {
   -4.547442,
   -4.222624,
   -4.547442,
   -5.197076};
   Double_t Graph_fy126[4] = {
   -4.5008,
   -3.9382,
   -3.3756,
   -3.3756};
   graph = new TGraph(4,Graph_fx126,Graph_fy126);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#089dcc");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph126 = new TH1F("Graph_Graph126","Graph",100,-5.294521,-4.125179);
   Graph_Graph126->SetMinimum(-4.61332);
   Graph_Graph126->SetMaximum(-3.26308);
   Graph_Graph126->SetDirectory(0);
   Graph_Graph126->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph126->SetLineColor(ci);
   Graph_Graph126->GetXaxis()->SetLabelFont(42);
   Graph_Graph126->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph126->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph126->GetXaxis()->SetTitleFont(42);
   Graph_Graph126->GetYaxis()->SetLabelFont(42);
   Graph_Graph126->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph126->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph126->GetYaxis()->SetTitleFont(42);
   Graph_Graph126->GetZaxis()->SetLabelFont(42);
   Graph_Graph126->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph126->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph126->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph126);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx127[4] = {
   -6.171528,
   -5.521893,
   -5.197076,
   -5.521893};
   Double_t Graph_fy127[4] = {
   1.6878,
   1.6878,
   2.2504,
   2.813};
   graph = new TGraph(4,Graph_fx127,Graph_fy127);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph127 = new TH1F("Graph_Graph127","Graph",100,-6.268973,-5.099631);
   Graph_Graph127->SetMinimum(1.57528);
   Graph_Graph127->SetMaximum(2.92552);
   Graph_Graph127->SetDirectory(0);
   Graph_Graph127->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph127->SetLineColor(ci);
   Graph_Graph127->GetXaxis()->SetLabelFont(42);
   Graph_Graph127->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph127->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph127->GetXaxis()->SetTitleFont(42);
   Graph_Graph127->GetYaxis()->SetLabelFont(42);
   Graph_Graph127->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph127->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph127->GetYaxis()->SetTitleFont(42);
   Graph_Graph127->GetZaxis()->SetLabelFont(42);
   Graph_Graph127->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph127->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph127->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph127);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx128[6] = {
   -6.496345,
   -6.171528,
   -5.521893,
   -5.197076,
   -5.521893,
   -6.171528};
   Double_t Graph_fy128[6] = {
   1.1252,
   0.5626,
   0.5626,
   1.1252,
   1.6878,
   1.6878};
   graph = new TGraph(6,Graph_fx128,Graph_fy128);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph128 = new TH1F("Graph_Graph128","Graph",100,-6.626272,-5.067149);
   Graph_Graph128->SetMinimum(0.45008);
   Graph_Graph128->SetMaximum(1.80032);
   Graph_Graph128->SetDirectory(0);
   Graph_Graph128->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph128->SetLineColor(ci);
   Graph_Graph128->GetXaxis()->SetLabelFont(42);
   Graph_Graph128->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph128->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph128->GetXaxis()->SetTitleFont(42);
   Graph_Graph128->GetYaxis()->SetLabelFont(42);
   Graph_Graph128->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph128->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph128->GetYaxis()->SetTitleFont(42);
   Graph_Graph128->GetZaxis()->SetLabelFont(42);
   Graph_Graph128->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph128->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph128->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph128);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx129[6] = {
   -6.496345,
   -6.171528,
   -5.521893,
   -5.197076,
   -5.521893,
   -6.171528};
   Double_t Graph_fy129[6] = {
   1.166027e-08,
   -0.5626,
   -0.5626,
   9.328214e-09,
   0.5626,
   0.5626};
   graph = new TGraph(6,Graph_fx129,Graph_fy129);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph129 = new TH1F("Graph_Graph129","Graph",100,-6.626272,-5.067149);
   Graph_Graph129->SetMinimum(-0.67512);
   Graph_Graph129->SetMaximum(0.67512);
   Graph_Graph129->SetDirectory(0);
   Graph_Graph129->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph129->SetLineColor(ci);
   Graph_Graph129->GetXaxis()->SetLabelFont(42);
   Graph_Graph129->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph129->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph129->GetXaxis()->SetTitleFont(42);
   Graph_Graph129->GetYaxis()->SetLabelFont(42);
   Graph_Graph129->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph129->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph129->GetYaxis()->SetTitleFont(42);
   Graph_Graph129->GetZaxis()->SetLabelFont(42);
   Graph_Graph129->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph129->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph129->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph129);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx130[6] = {
   -6.496345,
   -6.171528,
   -5.521893,
   -5.197076,
   -5.521893,
   -6.171528};
   Double_t Graph_fy130[6] = {
   -1.1252,
   -1.6878,
   -1.6878,
   -1.1252,
   -0.5626,
   -0.5626};
   graph = new TGraph(6,Graph_fx130,Graph_fy130);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph130 = new TH1F("Graph_Graph130","Graph",100,-6.626272,-5.067149);
   Graph_Graph130->SetMinimum(-1.80032);
   Graph_Graph130->SetMaximum(-0.45008);
   Graph_Graph130->SetDirectory(0);
   Graph_Graph130->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph130->SetLineColor(ci);
   Graph_Graph130->GetXaxis()->SetLabelFont(42);
   Graph_Graph130->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph130->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph130->GetXaxis()->SetTitleFont(42);
   Graph_Graph130->GetYaxis()->SetLabelFont(42);
   Graph_Graph130->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph130->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph130->GetYaxis()->SetTitleFont(42);
   Graph_Graph130->GetZaxis()->SetLabelFont(42);
   Graph_Graph130->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph130->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph130->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph130);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx131[4] = {
   -5.521893,
   -5.197076,
   -5.521893,
   -6.171528};
   Double_t Graph_fy131[4] = {
   -2.813,
   -2.2504,
   -1.6878,
   -1.6878};
   graph = new TGraph(4,Graph_fx131,Graph_fy131);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph131 = new TH1F("Graph_Graph131","Graph",100,-6.268973,-5.099631);
   Graph_Graph131->SetMinimum(-2.92552);
   Graph_Graph131->SetMaximum(-1.57528);
   Graph_Graph131->SetDirectory(0);
   Graph_Graph131->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph131->SetLineColor(ci);
   Graph_Graph131->GetXaxis()->SetLabelFont(42);
   Graph_Graph131->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph131->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph131->GetXaxis()->SetTitleFont(42);
   Graph_Graph131->GetYaxis()->SetLabelFont(42);
   Graph_Graph131->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph131->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph131->GetYaxis()->SetTitleFont(42);
   Graph_Graph131->GetZaxis()->SetLabelFont(42);
   Graph_Graph131->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph131->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph131->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph131);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx132[4] = {
   -7.14598,
   -6.496345,
   -6.171528,
   -6.496345};
   Double_t Graph_fy132[4] = {
   1.282629e-08,
   1.166027e-08,
   0.5626,
   1.1252};
   graph = new TGraph(4,Graph_fx132,Graph_fy132);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph132 = new TH1F("Graph_Graph132","Graph",100,-7.243425,-6.074083);
   Graph_Graph132->SetMinimum(0);
   Graph_Graph132->SetMaximum(1.23772);
   Graph_Graph132->SetDirectory(0);
   Graph_Graph132->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph132->SetLineColor(ci);
   Graph_Graph132->GetXaxis()->SetLabelFont(42);
   Graph_Graph132->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph132->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph132->GetXaxis()->SetTitleFont(42);
   Graph_Graph132->GetYaxis()->SetLabelFont(42);
   Graph_Graph132->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph132->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph132->GetYaxis()->SetTitleFont(42);
   Graph_Graph132->GetZaxis()->SetLabelFont(42);
   Graph_Graph132->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph132->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph132->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph132);
   
   ChannelMapping->AddBin(graph);
   
   Double_t Graph_fx133[4] = {
   -6.496345,
   -6.171528,
   -6.496345,
   -7.14598};
   Double_t Graph_fy133[4] = {
   -1.1252,
   -0.5626,
   1.166027e-08,
   1.282629e-08};
   graph = new TGraph(4,Graph_fx133,Graph_fy133);
   graph->SetName("Graph");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#263da8");
   graph->SetFillColor(ci);
   
   TH1F *Graph_Graph133 = new TH1F("Graph_Graph133","Graph",100,-7.243425,-6.074083);
   Graph_Graph133->SetMinimum(-1.23772);
   Graph_Graph133->SetMaximum(0.11252);
   Graph_Graph133->SetDirectory(0);
   Graph_Graph133->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph133->SetLineColor(ci);
   Graph_Graph133->GetXaxis()->SetLabelFont(42);
   Graph_Graph133->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph133->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph133->GetXaxis()->SetTitleFont(42);
   Graph_Graph133->GetYaxis()->SetLabelFont(42);
   Graph_Graph133->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph133->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph133->GetYaxis()->SetTitleFont(42);
   Graph_Graph133->GetZaxis()->SetLabelFont(42);
   Graph_Graph133->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph133->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph133->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph133);
   
   ChannelMapping->AddBin(graph);

   char* f_name = new char[200];
   
   //older_files
   //sprintf(f_name,"/home/shubham/work/HGCAL/CERNTB/channel_map_code/txt_files/new_fit//calib_file_layer_%d.txt",layer-1);
   
   //track inclusion follows
   sprintf(f_name,"/home/shubham/work/HGCAL/CERNTB/all_plotting_scripts/channel_map_code/txt_files/track_inclusion_31_aug_v11/calib_file_layer_%d.txt",layer-1);
   
   //std::ifstream in("/home/shubham/work/HGCAL/CERNTB/channel_map_code/txt_files/calib_file_layer_0.txt");
   //std::ifstream in("/home/shubham/work/HGCAL/CERNTB/channel_map_code/calib_file_layer_0.txt");
   std::ifstream in(f_name);

   if(in) cout<<"File Found!!!"<<endl;
   else {
      cout<<"File NOT found!!!.. returning"<<endl;
      return;
   }   
   int layer_,chip_,channel_,en_chan,entry;
   float adc,chi2,adc_err,grass, grass_err;
   int find_;
   float min = 1000.0, max = -10.0;
   int count =0;
   float mpv_v;
   //while(in>>a>>b>>c>>en_chan>>adc>>chi2>>entry>>grass>>grass_err>>mpv_v) {
   while(in>>layer_>>chip_>>channel_>>en_chan>>adc>>chi2>>adc_err>>entry>>grass>>grass_err>>mpv_v) {
   //while(in>>a>>b>>c>>adc>>chi2) {
     //en_chan = b*1000+c;
     find_=find_channel_id(layer,en_chan);
     float fill_;
     switch(select) {
     case 1: fill_ = en_chan; break;
     case 2: fill_ = adc; break;
     case 3: fill_ = chi2; break;
     case 4: fill_ = grass; break;
     case 5: fill_ = grass_err; break;
     }
     //float fill_ =en_chan;
     //float fill_ =en_chan;
     // if(en_chan == 62 || true) {
     //   cout<<"en_chan:"<<en_chan<<" ,bin:"<<find_<<" ,ADC:"<<adc<<" ,chi2:"<<chi2<<" ,grass:"<<grass<<" ,grass_err:"<<grass_err<<endl;}
     if(find_ > 0) {
       //if(en_chan == 62) { cout<<"**hello**"<<endl;ChannelMapping->SetBinContent(129,43.69);}
       ChannelMapping->SetBinContent(find_,fill_);
       //ChannelMapping->SetBinContent(find_,grass);
       //ChannelMapping->SetBinContent(find_,en_chan);
       if(fill_ < min && fill_ != 0) min = fill_;
       if(fill_ > max) max = fill_;

       count++;
     }
     else continue;
   }
   cout<<min<<" "<<max<<" "<<count<<endl;;
   ChannelMapping->SetEntries(127);
   ChannelMapping->SetOption("colztext");


   ChannelMapping->SetMaximum(max);
   ChannelMapping->SetMinimum(min);

   gStyle->SetOptStat(0);
   ChannelMapping->Draw("");
   
   channel_map->Modified();
   char* can_name = new char[200];
   char* d_name = new char[200];
   if(layer<11) {
      sprintf(d_name,"gifs/aug_31_track_inclusion_v11/layer0%d",layer);
   }
   else {
      sprintf(d_name,"gifs/aug_31_track_inclusion_v11/layer%d",layer);
   }
   switch(select){
   	case 1: sprintf(can_name,"%s/000_chan_map_layer_%d.gif",d_name,layer);break;
   	case 2: sprintf(can_name,"%s/001_adc_mip_layer_%d.gif",d_name,layer);break;
   	case 3: sprintf(can_name,"%s/002_chi2_ndf_layer_%d.gif",d_name,layer);break;
   	default: std::cout<<"NO CASE SATISFIED...returning!!!"<<std::endl; return;
   }
   channel_map->SaveAs(can_name);
   //delete channel_map;
}


void plotAllLayer(int start,int end){
	//channel_map(int layer, int select)
	for(int i_layer = start; i_layer <= end; i_layer++)	{
		// channel_map(i_layer, 1);
		channel_map(i_layer, 2);
		channel_map(i_layer, 3);
	}
}

//void plot(int layer, char* value)
