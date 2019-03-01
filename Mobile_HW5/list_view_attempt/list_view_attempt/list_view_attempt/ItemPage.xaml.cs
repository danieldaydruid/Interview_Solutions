using System;
using System.Collections.Generic;
using ProductModel;
using Xamarin.Forms;

namespace list_view_attempt
{
    public partial class ItemPage : ContentPage
    {
        public ItemPage(ProductData selectedItem)
        {
            InitializeComponent();


            name_item.Text = "Name: " + selectedItem.name_of_product;
            img_item.Source = selectedItem.img_url;
            item_code.Text = "Code: " + selectedItem.code_num;
            item_desc.Text = "Descrip: " + selectedItem.desc;
            price_item.Text = "$" + selectedItem.price;
            stars_for_item.Text = "Rating: " + selectedItem.star_rating;

        }
    }
}
