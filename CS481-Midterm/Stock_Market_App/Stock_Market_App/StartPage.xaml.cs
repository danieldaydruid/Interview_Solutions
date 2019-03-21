using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Xamarin.Forms;
using StockDataNamespace;
using DayModel;
using globals;
namespace Stock_Market_App {
    public partial class StartPage : ContentPage {
        public string API_Key = "KCDTWL8NI22FMT6M";
        DayData aDay = new DayData();
        double MAXIMUM = 99999.00, MINIMUM = 00000.00;
        public StartPage() {
            InitializeComponent();
        }
        async void Click_For_Get(object sender, EventArgs e) {
            string U_Input;
            U_Input = stockEntry.Text;
            string API_End = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY" + "&symbol=" + U_Input + "&apikey=" + API_Key;
            Uri StockAPI = new Uri(API_End);
            HttpClient client = new HttpClient();
            HttpResponseMessage response = await client.GetAsync(StockAPI);
            string Read_Json = await response.Content.ReadAsStringAsync();
            var Stock_Info = StockData.FromJson(Read_Json);
            Console.WriteLine(Read_Json);
            if(Read_Json != StockAppVars.Error) {
                StockAppVars.ListOfStocks = Stock_Info.TimeSeriesDaily.Values.ToList();
                StockAppVars.ListofDates = Stock_Info.TimeSeriesDaily.Keys.ToList();
                List<DayData> DaysList = new List<DayData>();
                for (int i = 0; i < StockAppVars.ListOfStocks.Count; i++) {
                    aDay.date = StockAppVars.ListofDates[i];
                    aDay.high = double.Parse(StockAppVars.ListOfStocks[i].The2High);
                    aDay.low = double.Parse(StockAppVars.ListOfStocks[i].The3Low);
                    aDay.close = double.Parse(StockAppVars.ListOfStocks[i].The4Close);
                    DaysList.Add(aDay);
                    aDay = new DayData();
                }
                historyListView.ItemsSource = DaysList;
                Populate();
                StockAppVars.R_Call = true;
            }
            else DisplayAlert("Something went wrong", "Provided stock symbol not valid", "OK");
        }
        void RetrieveHigh_RetrieveLow() {
            for (int i = 0; i < StockAppVars.ListOfStocks.Count; i++) {
                if (double.Parse(StockAppVars.ListOfStocks[i].The2High) >= MINIMUM) MINIMUM = double.Parse(StockAppVars.ListOfStocks[i].The2High);
                if (double.Parse(StockAppVars.ListOfStocks[i].The3Low) <= MAXIMUM) MAXIMUM = double.Parse(StockAppVars.ListOfStocks[i].The3Low);
            }
            lowestLabel.Text = MAXIMUM.ToString();
            highestLabel.Text = MINIMUM.ToString();
            MAXIMUM = 99999.00;
            MINIMUM = 00000.00;
        }
        void Populate() {
            RetrieveHigh_RetrieveLow();
        }

    }
}