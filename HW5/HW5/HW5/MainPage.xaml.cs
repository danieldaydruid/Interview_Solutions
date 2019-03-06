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
    }
}
