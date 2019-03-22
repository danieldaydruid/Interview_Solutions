using System;
using System.Collections.Generic;
using Xamarin.Forms;
using Stock_Info;
using DayModel;
using Entry = Microcharts.Entry;
using stock_app_variables;
using SkiaSharp;
using Microcharts;
namespace Stock_Market_App {
    public partial class Chart_Page : ContentPage {
        List<Entry> Stock_Listings = new List<Entry> { };
        Entry Enter_Here;
        float Placeholder_Value;
        public void Populate_Chart() {
            if (StockAppVars.R_Call == true) {
                for (int i = 0; i < StockAppVars.ListOfStocks.Count; i++) {
                    if (i % 6 == 0) {
                        Placeholder_Value = float.Parse(StockAppVars.ListOfStocks[i].The_High);
                        Enter_Here = new Entry(Placeholder_Value) {
                            Color = SKColor.Parse("#800000"),
                            Label = "---",
                            ValueLabel = StockAppVars.ListOfStocks[i].The_High,
                        };
                        Stock_Listings.Add(Enter_Here);
                        Stock_Listings.Reverse();
                    }
                }
            }
        }
        public Chart_Page() {
            InitializeComponent();
            Stock_Listings.Clear();
            ChartView.Chart = new LineChart { Entries = Stock_Listings };
        }
        public void Generate_Chart(object sender, System.EventArgs e) {
            Stock_Listings.Clear();
            Populate_Chart();
            ChartView.Chart = new LineChart { Entries = Stock_Listings };
        }
        void GenerateChartButton_Clicked(object sender, EventArgs e) {
            Stock_Listings.Clear();
            ChartView.Chart = new LineChart { Entries = Stock_Listings };
            Populate_Chart();
            ChartView.Chart = new LineChart { Entries = Stock_Listings };
        }
    }
}