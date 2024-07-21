//<App !Start!>
// FILE: [BMS.ino]
// Created by GUIslice Builder version: [0.17.b27]
//
// GUIslice Builder Generated File
//
// For the latest guides, updates and support view:
// https://github.com/ImpulseAdventure/GUIslice
//
//<App !End!>

// ------------------------------------------------
// Headers to include
// ------------------------------------------------

#include "BMS_GSLC.h"
#include <TFT_eSPI.h>
#include "Arduino.h"
#include "avdweb_Switch.h"
TFT_eSPI tft = TFT_eSPI();
#include <TFT_eWidget.h>   
#include "DHT.h"
#include "math.h"
#ifdef ESP8266
#include <WebServer.h>
#else  //ESP32
#include <WiFi.h>
#include <WebServer.h>
#endif
#include <ModbusIP_ESP8266.h>

ModbusIP mb;

#include <Wire.h>  
#include "web.h"
WebServer server (80);
// ------------------------------------------------
// Program Globals
// ------------------------------------------------
#define DHTPIN 27    
#define DHTTYPE DHT11   
const char *ssid ="Ko cần mật khẩu";
const char *pass ="20217834";
DHT dht(DHTPIN, DHTTYPE);
// Save some element references for direct access
//<Save_References !Start!>
gslc_tsElemRef* m_pElemSeekbar1_2 = NULL;
gslc_tsElemRef* m_pElemSeekbar1_2_3= NULL;
gslc_tsElemRef* m_pElemSeekbar1_2_3_5= NULL;
gslc_tsElemRef* m_pElemSeekbar1_2_6= NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }
float setpointt = 25; 
float setpointh = 75;
float setpointq1 = 0;
float setpointq2 = 0;
int giatriquat1 = 0;
int giatriquat2 = 0;
int q1 =0;
int q2 =0;
int quat1 = 0;
int quat2 = 0;
int i = 0;
int gio = 0;
int trang = 1; 
float h;
float t;
float chenh_lechh;
float chenh_lecht;
long ts;
long ts1;
GraphWidget gr = GraphWidget(&tft);    // Graph widget gr instance with pointer to tft
TraceWidget tr1 = TraceWidget(&gr);    // Graph trace 1
TraceWidget tr2 = TraceWidget(&gr);    // Graph trace 2   // Graph trace tr with pointer to gr

const float gxLow  = 0.0;
const float gxHigh = 100.0;
const float gyLow  = 0;
const float gyHigh = 100;

IPAddress local_IP(192,168,1,120);
IPAddress gateway(192,168,1,1);
IPAddress subnet (255,255,255,0);
IPAddress primaryDNS(8,8,8,8);
IPAddress secondaryDNS(8,8,4,4);

float nhietdo;
float doam;
int TTTB1,TTTB2,BienEF,BienGH,BienIK,BienLM;
long last = 0;
int Bienchedo = 0;

// ------------------------------------------------
// Callback Methods
// ------------------------------------------------
// Common Button callback
bool CbBtnCommon(void* pvGui,void *pvElemRef,gslc_teTouch eTouch,int16_t nX,int16_t nY)
{
  // Typecast the parameters to match the GUI and element types
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);

  if ( eTouch == GSLC_TOUCH_UP_IN ) {
    // From the element's ID we can determine which button was pressed.
    switch (pElem->nId) {
//<Button Enums !Start!>
      case E_ELEM_BTN1:
        gslc_SetPageCur(&m_gui,E_PG3);
        trang = 4;
        break;
      case E_ELEM_BTN2:
        gslc_SetPageCur(&m_gui,E_PG2);
        trang = 2;
        break;
      case E_ELEM_BTN5:
        gslc_SetPageCur(&m_gui,E_PG_MAIN);
        trang = 1;
        break;
      case E_ELEM_BTN6:
        gslc_SetPageCur(&m_gui,E_PG4);
        trang = 3;
        break;
      case E_ELEM_BTN9:
        gslc_SetPageCur(&m_gui,E_PG4);
        trang = 3;
        break;
      case E_ELEM_BTN10:
        gslc_SetPageCur(&m_gui,E_PG_MAIN);
        trang = 1;
        break;
      case E_ELEM_BTN11:
        gslc_SetPageCur(&m_gui,E_PG2);
        trang = 2;
        break;
      case E_ELEM_BTN12:
        gslc_SetPageCur(&m_gui,E_PG3);
        trang = 4;
        break;
      case E_ELEM_BTN13:
        quat1 = 1;
        break;
      case E_ELEM_BTN14:
        quat2 = 1;
        break;
      case E_ELEM_BTN15:
        quat1 = 0;
        break;
      case E_ELEM_BTN16:
        quat2 = 0;
        break;
//<Button Enums !End!>
      default:
        break;
    }
  }
  return true;
}
//<Checkbox Callback !Start!>
//<Checkbox Callback !End!>
//<Keypad Callback !Start!>
//<Keypad Callback !End!>
//<Spinner Callback !Start!>
//<Spinner Callback !End!>
//<Listbox Callback !Start!>
//<Listbox Callback !End!>
//<Draw Callback !Start!>
//<Draw Callback !End!>

// Callback function for when a slider's position has been updated
bool CbSlidePos(void* pvGui,void* pvElemRef,int16_t nPos)
{
  gslc_tsGui*     pGui     = (gslc_tsGui*)(pvGui);
  gslc_tsElemRef* pElemRef = (gslc_tsElemRef*)(pvElemRef);
  gslc_tsElem*    pElem    = gslc_GetElemFromRef(pGui,pElemRef);
  int16_t         nVal;

  // From the element's ID we can determine which slider was updated.
  switch (pElem->nId) {
//<Slider Enums !Start!>

    case E_ELEM_SEEKBAR2:
      // Fetch the slider position
      nVal = gslc_ElemXSeekbarGetPos(pGui,m_pElemSeekbar1_2);
      setpointt = nVal;
      break;
    case E_ELEM_SEEKBAR3:
      // Fetch the slider position
      nVal = gslc_ElemXSeekbarGetPos(pGui,m_pElemSeekbar1_2_3);
      setpointq2 = nVal;

      break;
    case E_ELEM_SEEKBAR5:
      // Fetch the slider position
      nVal = gslc_ElemXSeekbarGetPos(pGui,m_pElemSeekbar1_2_3_5);
      setpointq1 = nVal;
      break;
    case E_ELEM_SEEKBAR6:
      // Fetch the slider position
      nVal = gslc_ElemXSeekbarGetPos(pGui,m_pElemSeekbar1_2_6);
      setpointh = nVal;
      break;
//<Slider Enums !End!>
    default:
      break;
  }

  return true;
}
//<Tick Callback !Start!>
//<Tick Callback !End!>

void setup()
{
  // ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(9600);
  // Wait for USB Serial 
  //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used
  WiFi.begin("Ko cần mật khẩu", "20217834");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Đã kết nối WiFI với IP: ");
  Serial.println(WiFi.localIP());  // In ra IP
  gslc_InitDebug(&DebugOut);

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(5, OUTPUT);
  dht.begin();
  tft.begin();        
  tft.setRotation(1);

  // Graph area is 200 pixels wide, 150 pixels high, dark grey background
  gr.createGraph(200, 150, tft.color565(5, 5, 5));

  // x scale units is from 0 to 100, y scale units is -512 to 512
  gr.setGraphScale(gxLow, gxHigh, gyLow, gyHigh);

  // X grid starts at 0 with lines every 20 x-scale units
  // Y grid starts at -512 with lines every 64 y-scale units
  // blue grid
  gr.setGraphGrid(gxLow, 5, gyLow, 5, TFT_BLUE);

  // Draw empty graph, top left corner at pixel coordinate 40,10 on TFT

  gr.drawGraph(20, 70);

  // Start a trace with using red, trace points are in x and y scale units
  // In this example a horizontal line is drawn
  tr1.startTrace(TFT_RED);
  tr2.startTrace(TFT_GREEN);

  // Add points on graph to trace 1 using graph scale factors
  tr1.addPoint(0.0, 0.0);
  tr1.addPoint(100.0, 0.0);

  // Add points on graph to trace 2 using graph scale factors
  // Points are off graph so the plotted line is clipped to graph area
  tr2.addPoint(0.0, -100.0);
  tr2.addPoint(100.0, 100.0);


  // Start a new trace with using white
  tr1.startTrace(TFT_WHITE);
  tr2.startTrace(TFT_YELLOW);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
  server.on("/",ketnoi);
  server.on("/nhietdo",docnhietdo);
  server.on("/doam",docdoam);
  server.on("/setpointnhietdo",hamnhietdo);
  server.on("/setpointdoam",hamdoam);
  server.on("/input0",nhannhiet);
  server.on("/input1",nhanam);
  server.on("/vequat1",vequat1);
  server.on("/vequat2",vequat2);  
  server.on("/datquat1",datquat1);
  server.on("/datquat2",datquat2);  
  server.begin();
  dht.begin();
  mb.server();  //Start Modbus IP
  mb.addHreg(1);
  mb.addHreg(2);
  mb.addHreg(3);
  mb.addHreg(4);
  mb.addHreg(5);
  mb.addHreg(6);
  mb.addHreg(7);
  mb.addHreg(8);
  Wire.begin();
  dht.begin();
  ts = millis();
  }


// -----------------------------------
// Main event loop
// -----------------------------------
void XulyData(String InPut){
  int TimE=InPut.indexOf("E");
  int TimF=InPut.indexOf("F");
  int TimG=InPut.indexOf("G");
  int TimH=InPut.indexOf("H");
  int TimI=InPut.indexOf("I");
  int TimK=InPut.indexOf("K");
  int TimL=InPut.indexOf("L");
  int TimM=InPut.indexOf("M");
  if(TimE>=0 && TimF>=0){
    String DataEF = "";
    DataEF = InPut.substring(TimE+1,TimF);
    BienEF = DataEF.toInt();
    setpointt = BienEF;
    gslc_ElemXSeekbarSetPos (&m_gui, m_pElemSeekbar1_2, setpointt);
  }
  if(TimG>=0 && TimH>=0){
    String DataGH = "";
    DataGH = InPut.substring(TimG+1,TimH);
    BienGH = DataGH.toInt();
    setpointh = BienGH;
    gslc_ElemXSeekbarSetPos (&m_gui, m_pElemSeekbar1_2_6, setpointh);
  }
  if(TimI>=0 && TimK>=0){
    String DataIK = "";
    DataIK = InPut.substring(TimI+1,TimK);
    BienIK = DataIK.toInt();
    setpointq1 = BienIK;
    gslc_ElemXSeekbarSetPos (&m_gui, m_pElemSeekbar1_2_3_5,setpointq1);
  }
  if(TimL>=0 && TimM>=0){
    String DataLM = "";
    DataLM = InPut.substring(TimL+1,TimM);
    BienLM = DataLM.toInt();
    setpointq2 = BienLM;
    gslc_ElemXSeekbarSetPos (&m_gui, m_pElemSeekbar1_2_3,setpointq2);
  }
}
void ketnoi(){
  String s = MAIN_page;
  server.send(200,"text/html",s);
}
void hamnhietdo(){
  String guinhiet = String(setpointt);
  if(isnan(setpointt)){
    server.send(200,"text/plain","Gia tri khong hop le");
  }
  else{

    server.send(200,"text/plain",guinhiet);


  }
}
void hamdoam(){
  String guiam = String(setpointh);
  if(isnan(setpointh)){
    server.send(200,"text/plain","Gia tri khong hop le");
  }
  else{

    server.send(200,"text/plain",guiam);

  }
}
void docnhietdo(){
  t = dht.readTemperature();
  String nhietdo = String(t);
  if(isnan(t)){
    server.send(200,"text/plain","Loi cam bien");
  }
  else{

    server.send(200,"text/plain",nhietdo);
  }
}
void docdoam(){
  h = dht.readHumidity();
  String doam = String(h);
  if(isnan(h)){
    server.send(200,"text/plain","Loi cam bien");
  }
  else{
    server.send(200,"text/plain",doam);
  }
}
void nhannhiet(){
  String nhannhiet = "";
  nhannhiet = server.arg("input0");
  XulyData(String(nhannhiet));
}
void nhanam(){
  String nhanam = "";
  nhanam = server.arg("input1");
  XulyData(String(nhanam)); 
}
void vequat1(){
  String vequat1 = "";
  vequat1 = server.arg("vequat1");
  XulyData(String(vequat1)); 
}
void vequat2(){
  String vequat2 = "";
  vequat2 = server.arg("vequat2");
  XulyData(String(vequat2));

}
void datquat1(){
  String datquat1 = String(setpointq1);
  if(isnan(setpointq1)){
    server.send(200,"text/plain","Gia tri khong hop le");
  }
  else{
    server.send(200,"text/plain",datquat1);
  }
}
void datquat2(){
  String datquat2 = String(setpointq2);
  if(isnan(setpointq2)){
    server.send(200,"text/plain","Gia tri khong hop le");
  }
  else{
    server.send(200,"text/plain",datquat2);
  }
}
void loop()
{  
  mb.task();
  tft.setCursor(60, 5, 2);
  tft.println( WiFi.localIP());
  server.handleClient();
  // ------------------------------------------------
  // Update GUI Elements
  // ------------------------------------------------
  
  //TODO - Add update code for any text, gauges, or sliders
  
  // ------------------------------------------------
  // Periodically call GUIslice update function
  // ------------------------------------------------
  gslc_Update(&m_gui);
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();    
    while (WiFi.status() != WL_CONNECTED) {
      /*
    Vòng lặp chờ đến khi nào WiFi.status  =WL_CONNECTED
    tức là đã kết nối xong
    */
      tft.setCursor(60,50, 2);
      tft.println("Mat ket noi Wifi");
      delay(500);
      Serial.print(".");
    }
    Serial.println("");
    Serial.println("Đã kết nối WiFI với IP: ");
    Serial.println(WiFi.localIP());  // In ra IP
  }  
  if (WiFi.status() == WL_CONNECTED){
    tft.setCursor(60,50, 2);
    tft.println("Da ket noi Wifi   ");
    gslc_Update(&m_gui);
    h = dht.readHumidity();
    t = dht.readTemperature();
    if (setpointt < t){
     int coi_lanh = map(int(t-setpointt),0,30,255,0);  
     analogWrite(14,coi_lanh);
     analogWrite(5,255);
    }
    if (setpointt > t){
      int coi_nong = map(int(setpointt-t),0,30,255,0);   
      analogWrite(5,coi_nong);
      analogWrite(14,255);
    }
  }
if(trang == 2){
  tft.setCursor(135, 100, 2);
  tft.println(setpointt);
  tft.setCursor(135, 170, 2);
  tft.println(setpointh);
}
if(trang == 1){
  h = dht.readHumidity();
  t = dht.readTemperature();
  tft.setCursor(135, 100, 2);
  tft.println(t);
  tft.setCursor(135, 170, 2);
  tft.println(h);
}
if (trang == 4){
  i=i+1;
  if (i==10){
    gr.drawGraph(20, 70);
  }
  static uint32_t plotTime = millis();
  static float gx = 0.0, gy = 0.0;
  static float delta = 10.0;
  float a = dht.readHumidity(); 

  // Create a new plot point every 100ms
  if (millis() - plotTime >= 0.0001) {
    plotTime = millis();

  // Add a plot, first point in a trace will be a single pixel (if within graph area)
      tr1.addPoint(gx, gy);
      gx += 0.01;
      gy = a;
  if (gx > gxHigh) {
      gx = 0.0;
      gy = a;


      // Draw empty graph at 40,10 on display to clear old one
      // Start new trace
      gr.drawGraph(20, 70);
      tr1.startTrace(TFT_RED);
  }}
  static uint32_t plotTime1 = millis();
  static float gx1 = 0.0, gy1 = 0.0;


  // Create a new plot point every 100ms
  if (millis() - plotTime1 >= 0.0001) {
    plotTime1 = millis();

  // Add a plot, first point in a trace will be a single pixel (if within graph area)
      tr2.addPoint(gx1, gy1);
      gx1 += 0.01;
      gy1 = dht.readTemperature();
  if (gx1 > gxHigh) {
      gx1 = 0.0;
      gy1 = dht.readTemperature();;


      // Draw empty graph at 40,10 on display to clear old one
      // Start new trace
      gr.drawGraph(20, 70);
      tr2.startTrace(TFT_RED);
  }}
}
if(trang!=4){
    i=0;
  }
if(quat1 == 1&&q1==0){
      int giatriquat1 = map(setpointq1,0,100,255,0);   
      analogWrite(13,giatriquat1);  
}
if(quat1 == 0&&q1==0){
      analogWrite(13,255);   
}
if(quat2 == 1&&q1==0){
      int giatriquat2 = map(setpointq2,0,100,255,0);   
       analogWrite(12,giatriquat2);  
}
if(quat2 == 0&&q1==0){
      analogWrite(12,255);   
}
if (millis() > ts + 2000) {
    ts = millis();
    //Setting raw value (0-1024)
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float hieu = h- setpointh+100;
    mb.Hreg(1, t);
    mb.Hreg(2, h);
    mb.Hreg(3,setpointt);
    mb.Hreg(4,setpointh);
    mb.Hreg(5,setpointq1);
    mb.Hreg(6,setpointq2);
    mb.Hreg(8,hieu);  
    q1 = mb.Hreg(7);
    Serial.println(q1); 
    if(q1==100){
        analogWrite(13,0);
        analogWrite(12,0);  
    }     
  }
}


