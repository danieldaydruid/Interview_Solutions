using System;
using System.Collections.Generic;
using ProductModel;
using Xamarin.Forms;

namespace HW5
{
    public partial class ItemPage : ContentPage
    {
        public ItemPage(ProductData selectedItem)
        {
            InitializeComponent();


            itemName.Text = "Name: " + selectedItem.ProductName;
            itemImage.Source = selectedItem.ImageUrl;
            itemDescription.Text = "Description: " + selectedItem.Description;
            itemPrice.Text = "$" + selectedItem.Price;
            itemStars.Text = "Rating: " + selectedItem.StarRating;

        }
    }
}
