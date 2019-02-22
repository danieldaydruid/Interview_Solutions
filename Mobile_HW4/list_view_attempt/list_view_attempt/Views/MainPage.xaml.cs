using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using list_view_attempt.ViewModels;
using Xamarin.Forms;
using System.Collections.ObjectModel;
using list_view_attempt.Models;


namespace list_view_attempt
{
    public partial class MainPage : ContentPage
    {
        private ObservableCollection<Product> productArray;
            
        void createList()
        {
            productArray = new ObservableCollection<Product>
            {
                new Product
                {
                    Name = "Pizza",
                    Image = "https://upload.wikimedia.org/wikipedia/commons/a/a3/Eq_it-na_pizza-margherita_sep2005_sml.jpg",
                    Price = "Homemade: $30\nStorebought: $3"

                },
                new Product
                {
                    Name = "Pot Pie",
                    Image = "https://images-gmi-pmc.edge-generalmills.com/79e6dd6b-a8d4-477f-8037-9a7349a6a3be.jpg",
                    Price = "Homemade: $20\nStorebought: $7"

                },
                new Product
                {
                    Name = "Grilled Cheese",
                    Image = "https://cdn.apartmenttherapy.info/image/fetch/f_auto,q_auto,w_600,h_750,c_fit,fl_strip_profile/https://s3.amazonaws.com/pixtruder/original_images/c3a8c1079c6970caf7188768531f20699d22f0d7",
                    Price = "Homemade: $10\nStorebought: $5"

                },
                new Product
                {
                    Name = "Tomato Soup",
                    Image = "https://s3.amazonaws.com/finecooking.s3.tauntonclud.com/app/uploads/2017/04/18173927/051091055_01-main.jpg",
                    Price = "Homemade: $25\nStorebought: $2"

                },
                new Product
                {
                    Name = "Vanilla Ice Cream",
                    Image = "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR9amQ3m77-XKt5RKV8WXlKBQm7kQx0NIOi1o3-viza25KDUEgl3w",
                    Price = "Homemade: $50\nStorebought: $6"

                },
                new Product
                {
                    Name = "Vanilla Ice",
                    Image = "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR_KH6JXlYkln3qhe20qcJUa87hMEW5k4QwxYcwUU3moHV_kqZfXA",
                    Price = "Priceless"

                }
            };
        }

        public MainPage()
        {
            InitializeComponent();
            createList();
            CurrencyList.Refreshing += CurrencyList_Refreshing;
            CurrencyList.ItemTapped += CurrencyList_ItemTapped;
            CurrencyList.ItemsSource = productArray;
        }

        void CurrencyList_ItemTapped(object sender, ItemTappedEventArgs e)
        {
            Console.WriteLine("CurrencyList_ItemTapped");
            productArray.Remove(e.Item as Product);
        }


        void CurrencyList_Refreshing(object sender, EventArgs e)
        {
            Console.WriteLine("refreshing");
            createList();
            CurrencyList.ItemsSource = productArray;
            CurrencyList.EndRefresh();
        }
    }

}
