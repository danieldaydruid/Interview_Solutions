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
        List<Entry> entries = new List<Entry> { };
        Entry entry;
        float temp;
        public void fillChartList() {
            if(StockAppVars.R_Call == true) {
                for (int i = 0; i < StockAppVars.ListOfStocks.Count; i++) {
                    if(i % 5 == 0) {
                        temp = float.Parse(StockAppVars.ListOfStocks[i].The2High);
                        entry = new Entry(temp) {
                            Color = SKColor.Parse("#6fc1e8"),
                            Label = "",
                            ValueLabel = StockAppVars.ListOfStocks[i].The2High,
                        };
                        entries.Add(entry);
                        entries.Reverse();
                    }
                }
            }
        }
        public ChartsPage() {
            InitializeComponent();
            entries.Clear();
            ChartView.Chart = new LineChart { Entries = entries };
        }
        void GenerateChartButton_Clicked(object sender, EventArgs e) {
            entries.Clear();
            ChartView.Chart = new LineChart { Entries = entries };
            fillChartList();
            ChartView.Chart = new LineChart { Entries = entries };
        }
    }
}