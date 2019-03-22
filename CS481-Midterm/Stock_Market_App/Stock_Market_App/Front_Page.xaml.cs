using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Xamarin.Forms;
using Stock_Info;
using DayModel;
using stock_app_variables;
namespace Stock_Market_App {
    public partial class Front_Page : ContentPage {
        public string API_Key = "KCDTWL8NI22FMT6M";
        DayData Single_Day = new DayData();
        string temp;
        double MAXIMUM = 99999.00, MINIMUM = 00000.00;
        string[] ThisIsTheMonth = { "Januray", "Januray", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        public Front_Page() {
            InitializeComponent();
        }
        async void Click_For_Get(object sender, EventArgs e) {
            string U_Input;
            U_Input = Enter_Stock.Text;
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
                    //Single_Day.date = StockAppVars.ListofDates[i];
                    Single_Day.date = StockAppVars.ListofDates[i].ToString();
                    temp = Single_Day.date.Substring(4, 4).Trim('-');
                    Single_Day.date = ThisIsTheMonth[Convert.ToInt32(temp)] + " " + Single_Day.date.Substring(8, 2) + ", " + Single_Day.date.Substring(0, 4);
                    Single_Day.high = double.Parse(StockAppVars.ListOfStocks[i].The_High);
                    Single_Day.low = double.Parse(StockAppVars.ListOfStocks[i].The_Low);
                    Single_Day.close = double.Parse(StockAppVars.ListOfStocks[i].The_Close);
                    DaysList.Add(Single_Day);
                    Single_Day = new DayData();
                }
                historyListView.ItemsSource = DaysList;
                Populate();
                StockAppVars.R_Call = true;
            }
            else DisplayAlert("Something went wrong", "Provided stock symbol not valid", "OK");
        }
        void RetrieveHigh_RetrieveLow() {
            for (int i = 0; i < StockAppVars.ListOfStocks.Count; i++) {
                if (double.Parse(StockAppVars.ListOfStocks[i].The_High) >= MINIMUM) MINIMUM = double.Parse(StockAppVars.ListOfStocks[i].The_High);
                if (double.Parse(StockAppVars.ListOfStocks[i].The_Low) <= MAXIMUM) MAXIMUM = double.Parse(StockAppVars.ListOfStocks[i].The_Low);
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