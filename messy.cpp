#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;


// int * a = new int[11];

//plane parameters
int infected = 0;

void sick_pilot(double x){
double infection_rate = x;
double nIR = (1 - infection_rate);
int passengers = (320 + rand() % 69);
int expected = passengers * infection_rate;
int variance = expected * nIR;
int lbound = (expected - variance);
int upper_bound = (expected + variance);
int ipassengers = (lbound + rand() % (2*variance));
infected = ipassengers;
}

string flights[18] = {"San Francisco","Los Angeles","Phoenix","Las Vegas","Houston","Miami","New York City","Atlanta","Portland","Seattle","Chicago","Nashville","Boston","Philedelphia","Detroit","Milwaukee","Salt Lake City","Kansas City"};
int citypop[18] = {3318000,12488000,4652000,2839000,6603000,6215000,18867000,5100000,2197000,3489000,8901000,1294000,4327000,5756000,3521000,1448000,1192000,1711000};

string NoCal[6] = {"Los Angeles", "Phoenix", "Las Vegas", "Portland", "Seattle", "Salt Lake City"};
string SoCal[10] = {"San Francisco","Phoenix","Las Vegas","Houston","Miami","New York City","Atlanta","Portland","Chicago","Nashville"};
string Arizona[5] = {"San Francisco","Los Angeles","Las Vegas","Houston","Salt Lake City"};
string Nevada[7] = {"San Francisco","Los Angeles","Phoenix","Houston","Miami","New York City","Atlanta"};
string Texas[11] = {"Los Angeles","Phoenix","Las Vegas","Miami","New York City","Atlanta","Chicago","Nashville","Philedelphia","Salt Lake City","Kansas City"};
string Florida[10] = {"Los Angeles","Phoenix","Las Vegas","Houston","New York City","Atlanta","Chicago","Philedelphia","Milwaukee","Kansas City"};
string NewYork[11] = {"Los Angeles","Las Vegas","Houston","Miami","Atlanta","Chicago","Nashville","Boston","Philedelphia","Detroit","Milwaukee"};
string Georgia[6] = {"Los Angeles","Las Vegas","Houston","Miami","New York City","Philedelphia"};
string Oregon[4] = {"San Francisco","Los Angeles","Seattle","Salt Lake City"};
string Washington[3] = {"San Francisco","Portland","Salt Lake City"};
string Illinois[4] = {"Los Angeles","Houston","Miami","New York City"};
string Tennessee[4] = {"Los Angeles","Houston","New York City","Philedelphia"};
string NewEngland[2] = {"New York City","Detroit"};
string Pennsyl[6] = {"Houston","Miami","New York City","Atlanta","Nashville","Detroit"};
string Michigan[3] = {"New York City","Boston","Philedelphia"};
string Wisconsin[2] = {"Miami","New York City"};
string Utah[6] = {"San Francisco","Phoenix","Houston","Portland","Seattle","Kansas City"};
string Missouri[3] = {"Houston","New York City","Salt Lake City"};

double maximum = 0.0;
double Infected[100];
double Susceptible[100];
double Recovery[100];
double Results[100][10];

//SIR initial population
int sac = 0;
int lax = 0;
int pho = 0;
int lav = 0;
int hou = 0;
int mia = 0;
int nyc = 0;
int atl = 0;
int por = 0;
int sea = 0;
int chi = 0;
int nash = 0;
int bos = 0;
int phil = 0;
int det = 0;
int mil = 0;
int slc = 0;
int kcc = 0;

//-0: initial infected pop   -1:city pop 
double Tsac[5] = {0,3318000.0,0,0,0};
double Tlax[5] = {0,12488000.0,0,0,0};
double Tpho[5] = {0,4652000.0,0,0,0};
double Tlav[5] = {0,2839000.0,0,0,0};
double Thou[5] = {0,6603000.0,0,0,0};
double Tmia[5] = {0,6215000.0,0,0,0};
double Tnyc[5] = {0,18867000.0,0,0,0};
double Tatl[5] = {0,5100000.0,0,0,0};
double Tpor[5] = {0,2197000.0,0,0,0};
double Tsea[5] = {0,3489000.0,0,0,0};
double Tchi[5] = {0,8901000.0,0,0,0};
double Tnash[5] = {0,1294000.0,0,0,0};
double Tbos[5] = {0,4327000.0,0,0,0};
double Tphil[5] = {0,5756000.0,0,0,0};
double Tdet[5] = {0,3521000.0,0,0,0};
double Tmil[5] = {0,1448000.0,0,0,0};
double Tslc[5] = {0,1192000.0,0,0,0};
double Tkcc[5] = {0,1711000.0,0,0,0};
double Total[5] = {0,0,0,0,0};

int loc = 0;
string flight_path[14] = {};
string current_city = "";

void add_path() {
  int i = 0;
  while (i < 14 && flight_path[i] != ""){
    i++;
  }
  flight_path[i] = current_city;
}

void show_path()
{
  int size = sizeof(flight_path)/sizeof(string);
  for (int i = 0; i<size; i++)
  {
    if(flight_path[i] != ""){
      cout << flight_path[i] << " " << "|" << " ";
    }
   if(flight_path[i] == ""){
      cout << flight_path[i];
    }
  }
  cout << "\n";
}

void rand_weight(int * a){
  int value = rand() % 100;
  int length = (int)sizeof(a)/sizeof(int);
  for(int i = 0; i < length; i++ ){
    if(value < a[i]){
      loc = i;
    }
    value -= a[i];
  }
}

void start_point(double x){
  int size = sizeof(flights)/sizeof(string);
  int loc = (rand() % size);
  sick_pilot(x);
  current_city = flights[loc];
  add_path();
}

void match(string n){
  int i = 0;
  while (i < 18 && flights[i] != n){
    i++;
  }
  loc = i;
}

void combine(){
  for(int i = 0; i < 5; i++){
    Total[i] = Tsac[i] + Tlax[i] + Tpho[i] + Tlav[i] + Thou[i] + Tmia[i] + Tnyc[i] + Tatl[i] 
    + Tpor[i] + Tsea[i] + Tchi[i] + Tnash[i] + Tbos[i] + Tphil[i] + Tdet[i] + Tmil[i] 
    + Tslc[i] + Tkcc[i];
  }
}

void summation(){
  int sum = 0;
  for(int i = 0; i < 18; i++){
    sum += citypop[i];
  }
  cout << sum << endl;
}

void next_city(double x){
  switch(loc+1)
  {
    case 1:
        {
        int weights[6]= {30,10,20,15,15,10};
        sac += infected;
        Tsac[0] = sac;
        sick_pilot(x);
        rand_weight(weights);
        string next = NoCal[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
        }
    case 2:
        {
        int weights[10] = {8,5,12,15,15,20,12,3,5,5};
        lax += infected;
        Tlax[0] = lax;
        sick_pilot(x);
        rand_weight(weights);
        string next = SoCal[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
        }
    case 3:
        {
        int weights[5] = {15,30,20,30,5};
        pho += infected;
        Tpho[0] = pho;
        sick_pilot(x);
        rand_weight(weights);
        string next = Arizona[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
        }
    case 4:
        {
        int weights[7] = {10,25,10,15,12,20,8};
        lav += infected;
        Tlav[0] = lav;
        sick_pilot(x);
        rand_weight(weights);
        string next = Nevada[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
        }
    case 5:
        {
        int weights[11] = {15,6,10,15,15,10,4,10,5,5,5};
        hou += infected;
        Thou[0] = hou;
        sick_pilot(x);
        rand_weight(weights);
        string next = Texas[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
        }
    case 6:
        {
        int weights[10] = {15,5,15,15,20,10,5,5,5,5};
        mia += infected;
        Tmia[0] = mia;
        sick_pilot(x);
        rand_weight(weights);
        string next = Florida[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
        }
    case 7:
        {
        int weights[11] = {15,10,15,10,10,7,10,7,6,5,5};
        nyc += infected;
        Tnyc[0] = nyc;
        sick_pilot(x);
        rand_weight(weights);
        string next = NewYork[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
        }
    case 8:
		{
        int weights[6]={15,15,20,15,30,5};
        atl += infected;
        Tatl[0] = atl;
        sick_pilot(x);
        rand_weight(weights);
        string next = Georgia[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 9:
		{
        int weights[4] = {30,20,30,20};
        por += infected;
        Tpor[0] = por;
        sick_pilot(x);
        rand_weight(weights);
        string next = Oregon[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 10:
		{
        int weights[3] = {50,30,20};
        sea += infected;
        Tsea[0] = sea;
        sick_pilot(x);
        rand_weight(weights);
        string next = Washington[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 11:
		{
        int weights[4] = {20,30,20,30};
        chi += infected;
        Tchi[0] = chi;
        sick_pilot(x);
        rand_weight(weights);
        string next = Illinois[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 12:
		{
        int weights[4] = {15,35,35,15};
        nash += infected;
        Tnash[0] = nash;
        sick_pilot(x);
        rand_weight(weights);
        string next = Tennessee[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 13:
		{
        int weights[2] = {65,35};
        bos += infected;
        Tbos[0] = bos;
        sick_pilot(x);
        rand_weight(weights);
        string next = NewEngland[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 14:
		{
        int weights[6] = {20,15,30,20,10,5};
        phil += infected;
        Tphil[0] = phil;
        sick_pilot(x);
        rand_weight(weights);
        string next = Pennsyl[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 15:
		{
        int weights[3] = {50,20,30};
        det += infected;
        Tdet[0] = det;
        sick_pilot(x);
        rand_weight(weights);
        string next = Michigan[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 16:
		{
        int weights[2] = {40,60};
        mil += infected;
        Tmil[0] = mil;
        sick_pilot(x);
        rand_weight(weights);
        string next = Wisconsin[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 17:
		{
        int weights[6] = {20,10,30,15,15,10};
        slc += infected;
        Tslc[0] = slc;
        sick_pilot(x);
        rand_weight(weights);
        string next = Utah[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    case 18:
		{
        int weights[3] = {40,40,20};
        kcc += infected;
        Tkcc[0] = kcc;
        sick_pilot(x);
        rand_weight(weights);
        string next = Missouri[loc];
        match(next);
        current_city = flights[loc];
        add_path();
        break;
		}
    default:
		{
    	cout << "Error on loc" << endl;
    	break;
		}
  }
}

void MaxValue(double a[]){
  for(int i = 0; i < 100; i++)
  {
    if(maximum < a[i]){
      maximum = a[i];
    }
  }
  cout << maximum << endl;
}

void SIR_model(double a[], double b, double y, int c){           //b- infection rate y- recovery rate c- index position for results
  //int ndays = 100;           //number of days for SIR
  double dt = 1.0;             //time step
  double beta = b;             // infection rate
  double yamma = y;            //recovery rate
  double glove = 0.0;          //catch

  Infected[0] = a[0]/a[1];
  Susceptible[0] = 1.0 - Infected[0];
  Recovery[0] = 0;

  for(int i = 0; i < 100; i++){
    Susceptible[i+1] = Susceptible[i] - beta*(Susceptible[i]*Infected[i])*dt;
    Infected[i+1] = Infected[i] + (beta*Susceptible[i]*Infected[i] - yamma*Infected[i])*dt;
    Recovery[i+1] = Recovery[i] + (yamma*Infected[i])*dt;
    
    glove =  Infected[i];
    Results[i][c] = glove;
  }

  cout << Infected[0] << endl;
  MaxValue(Infected);
}

void DataPoint(string a){
  ofstream myfile;
  myfile.open(a);
  myfile << "0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.99" << endl; 
  for(int i = 0; i<100; i++){
    myfile << Results[i][0] << "," << Results[i][1] << "," << Results[i][2] << "," 
    << Results[i][3] << "," << Results[i][4] << "," << Results[i][5]
    << "," << Results[i][6] << "," << Results[i][7] << "," << Results[i][8] << "," << Results[i][9] << endl;
  }
}

/* void DeleteArray(int a[]) // Do not delete this otherwise valgrind will get angry
{
    delete [] a;
}*/

int main ()
{
  srand(time(NULL));

  cout << "Recovery takes one week" << endl;

  start_point(0.1);
  for (int i = 0; i < 13; i++){
    next_city(0.10);
  }
  cout << "The Flight Path is: " << endl;
  show_path();
  combine();
  cout << "Total initial infected" << endl;
  cout << Total[0] << endl;
  cout << "Total population" << endl;
  cout << Total[1] << endl;
  SIR_model(Total, 0.10, (1.0/7.0), 0);
  cout << "Max individuals infected when infection rate is " << 0.10 << endl;
  cout << (maximum * Total[1]) << endl;


  start_point(0.20);
  for (int i = 0; i < 13; i++){
    next_city(0.20);
  }
  cout << "The Flight Path is: " << endl;
  show_path();
  combine();
  cout << "Total initial infected" << endl;
  cout << Total[0] << endl;
  cout << "Total population" << endl;
  cout << Total[1] << endl;
  SIR_model(Total, 0.20, (1.0/7.0), 1);
  cout << "Max individuals infected when infection rate is " << 0.20 << endl;
  cout << (maximum * Total[1]) << endl;

  SIR_model(Total, 0.30, (1.0/7.0), 2);
  cout << "Max individuals infected when infection rate is " << 0.30 << endl;
  cout << (maximum * Total[1]) << endl;

  SIR_model(Total, 0.40, (1.0/7.0), 3);
  cout << "Max individuals infected when infection rate is " << 0.40 << endl;
  cout << (maximum * Total[1]) << endl;

  SIR_model(Total, 0.50, (1.0/7.0), 4);
  cout << "Max individuals infected when infection rate is " << 0.50 << endl;
  cout << (maximum * Total[1]) << endl;

  SIR_model(Total, 0.60, (1.0/7.0), 5);
  cout << "Max individuals infected when infection rate is " << 0.60 << endl;
  cout << (maximum * Total[1]) << endl;

  SIR_model(Total, 0.70, (1.0/7.0), 6);
  cout << "Max individuals infected when infection rate is " << 0.7 << endl;
  cout << (maximum * Total[1]) << endl;

  SIR_model(Total, 0.80, (1.0/7.0), 7);
  cout << "Max individuals infected when infection rate is " << 0.80 << endl;
  cout << (maximum * Total[1]) << endl;

  SIR_model(Total, 0.90, (1.0/7.0), 8);
  cout << "Max individuals infected when infection rate is " << 0.90 << endl;
  cout << (maximum * Total[1]) << endl;

  SIR_model(Total, 0.99, (1.0/7.0), 9);
  cout << "Max individuals infected when infection rate is " << 0.99 << endl;
  cout << (maximum * Total[1]) << endl;

  DataPoint("infect.csv");

  /* DeleteArray(a);
  cout << "Array(s) has been deleted" << endl;*/

  return 0;
}
