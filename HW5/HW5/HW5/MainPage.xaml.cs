using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using Xamarin.Forms;
using ProductModel;
using Newtonsoft.Json.Linq;
using System;

namespace HW5
{

    public partial class MainPage : ContentPage
    {
        public List<ProductData> items;
         
        public string fileName = "./products.json";

        public MainPage()
        {
            InitializeComponent();
            LoadJson();
        }
        private async void MagicBtn_Clicked(object sender, EventArgs e)
        {
            var menuItem = (Button)sender;
            var itemClicked = menuItem.CommandParameter as ProductData;
            await Navigation.PushAsync(new ItemPage(itemClicked));
        }
        public void LoadJson()
        {
            using (StreamReader r = new StreamReader(fileName))
            {
                string json = r.ReadToEnd();
                items = JsonConvert.DeserializeObject<List<ProductData>>(json);
            }
             ProductsListView.ItemsSource = items;
        }

        void Handle_More(object sender, System.EventArgs e)
        {
            var menu = (MenuItem)sender;
            var itemClicked = menu.CommandParameter as ProductData;
            Navigation.PushAsync(new ItemPage(itemClicked));
        }
        void Handle_Prime(object sender, System.EventArgs e)
        {
            var menuItem = (MenuItem)sender;
            var itemClicked = menuItem.CommandParameter as ProductData;
            items.Remove(itemClicked);
            Random rand = new Random();
            bool isPrime = true;
            int n = rand.Next(1000000000);
            for (int i = 2; i <= n / 2; ++i)
            {
                if(n % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            string myString = n.ToString();
            if (isPrime)
            {

                DisplayAlert("Alert", myString, "It's prime!");
            }
            else
            {

                DisplayAlert("Alert", myString, "It's not prime!");
            }


        }

        void Handle_Refreshing(object sender, System.EventArgs e)
        {
            items.Clear();
            LoadJson();
            ProductsListView.IsRefreshing = false;
        }
    }
}
