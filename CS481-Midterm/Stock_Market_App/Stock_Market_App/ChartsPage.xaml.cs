using System;
using System.Collections.Generic;

using Xamarin.Forms;
using StockDataNamespace;
using DayModel;
using Entry = Microcharts.Entry;
using globals;
using SkiaSharp;
using Microcharts;
namespace Stock_Market_App {
    public partial class ChartsPage : ContentPage {
        List<Entry> Stock_Listings = new List<Entry> { };
        Entry Enter_Here;
        float Placeholder_Value;
        public void fillChartList() {
            if(StockAppVars.R_Call == true) {
                for (int i = 0; i < StockAppVars.ListOfStocks.Count; i++) {
                    if(i % 5 == 0) {
                        Placeholder_Value = float.Parse(StockAppVars.ListOfStocks[i].The2High);
                        Enter_Here = new Entry(Placeholder_Value) {
                            Color = SKColor.Parse("#6fc1e8"),
                            Label = "",
                            ValueLabel = StockAppVars.ListOfStocks[i].The2High,
                        };
                        Stock_Listings.Add(Enter_Here);
                        Stock_Listings.Reverse();
                    }
                }
            }
        }
        public ChartsPage() {
            InitializeComponent();
            Stock_Listings.Clear();
            ChartView.Chart = new LineChart { Entries = Stock_Listings };
        }
        void GenerateChartButton_Clicked(object sender, EventArgs e) {
            Stock_Listings.Clear();
            ChartView.Chart = new LineChart { Entries = Stock_Listings };
            fillChartList();
            ChartView.Chart = new LineChart { Entries = Stock_Listings };
        }
    }
}