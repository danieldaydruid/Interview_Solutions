using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;
using StockDataNamespace;
using DayModel;
using System.Collections.Generic;

[assembly: XamlCompilation(XamlCompilationOptions.Compile)]
namespace Stock_Market_App
{
    public partial class App : Application
    {



        public App()
        {
            InitializeComponent();

            MainPage = new MainPage();
        }

        protected override void OnStart()
        {
            // Handle when your app starts
        }

        protected override void OnSleep()
        {
            // Handle when your app sleeps
        }

        protected override void OnResume()
        {
            // Handle when your app resumes
        }
    }
}
