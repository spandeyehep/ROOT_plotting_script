int getChan(int chip, int channel) {
  if(channel > 62) return -1;
  if(channel%2 != 0) return -1;
  return ((chip*32)+(channel/2))+1;
}


void graph_custom(int layer)
{


  char* f_name = new char[200];
  // sprintf(f_name,"/home/shubham/work/HGCAL/CERNTB/txt_files/track_inclusion_errors/calib_file_layer_%d.txt",layer-1);
  // sprintf(f_name,"./txt_files/v11/calib_file_layer_%d.txt",layer-1);
  sprintf(f_name,"./txt_files/official/official_file_layer_%d.txt",layer-1);
  cout<<"f_name: "<<f_name<<endl;
  std::ifstream in(f_name);
  
  if(in) cout<<"File Found!!!"<<endl;
  
  // int layer_,chip_,channel_,en_chan,entry;
  // float adc,adc_err,chi2,grass, grass_err, mpv;
  // int find_;
  // float min = 1000.0, max = -10.0;


  int layer_, module_, chip_, channel_;
  float adc;

  std::ofstream myfile;
  // sprintf(f_name,"calib_file_layer_%d_new.txt",layer-1);
  sprintf(f_name,"offical_file_layer_%d_new.txt",layer-1);
  myfile.open(f_name);
  
  float x_err = 0.0;
  float y_err = 0.0;
  
  char* line = new char[200];
  int chan_no;
  // while(in>>layer_>>chip_>>channel_>>en_chan>>adc>>chi2>>adc_err>>entry>>grass>>grass_err>>mpv) {
  while(in>>layer_>>module_>>chip_>>channel_>>adc) {
    chan_no = getChan(chip_,channel_);
    // y_err = adc_err;
    sprintf(line,"%d %.2f %.2f %.2f\n",chan_no,adc,x_err,y_err);
    //cout<<line;
    myfile << line;
  }
  myfile.close();

}


void draw_all(int start, int end) {
  for(int i = start; i <= end; i++) {
    graph_custom(i);
  }
}
