using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using list_view_attempt.Models;
using Xamarin.Forms;

namespace list_view_attempt.ViewModels
{
    public class ProductsViewModel
    {
    public ObservableCollection<Product> Products { get; set; }

        public Command<Product> RemoveCommand
        {
            get
            {
                return new Command<Product>((product) =>
                {
                    Products.Remove(product);
                });
            }
        }

        public ProductsViewModel() {
            Products = new ObservableCollection<Product>
            {
                new Product
                {
                    Name = "Laptop",
                    Image = "https://upload.wikimedia.org/wikipedia/commons/a/a3/Eq_it-na_pizza-margherita_sep2005_sml.jpg",
                    Price = "900"

                },
                new Product
                {
                    Name = "Xbox One",
                    Image = "https://upload.wikimedia.org/wikipedia/commons/a/a3/Eq_it-na_pizza-margherita_sep2005_sml.jpg",
                    Price = "900"

                },
                new Product
                {
                    Name = "Camera",
                    Image = "https://upload.wikimedia.org/wikipedia/commons/a/a3/Eq_it-na_pizza-margherita_sep2005_sml.jpg",
                    Price = "900"

                },
                new Product
                {
                    Name = "Bike",
                    Image = "https://upload.wikimedia.org/wikipedia/commons/a/a3/Eq_it-na_pizza-margherita_sep2005_sml.jpg",
                    Price = "Homemade: $50"

                },
                new Product
                {
                    Name = "TV",
                    Image = "https://upload.wikimedia.org/wikipedia/commons/a/a3/Eq_it-na_pizza-margherita_sep2005_sml.jpg",
                    Price = "Homemade: $50"

                },
                new Product
                {
                    Name = "Smartphone",
                    Image = "https://upload.wikimedia.org/wikipedia/commons/a/a3/Eq_it-na_pizza-margherita_sep2005_sml.jpg",
                    Price = "$5"

                }
            };
        }

    }
}
