namespace globals
{
    using StockDataNamespace;
    using System.Collections.Generic;

    public static class StockAppVars {
        public static List<TimeSeriesDaily> ListOfStocks;
        public static List<string> ListofDates;
        public static bool R_Call = false;
        public static string Error = "{\n    \"Error Message\": \"Invalid API call. Please retry or visit the documentation (https://www.alphavantage.co/documentation/) for TIME_SERIES_DAILY.\"\n}";
    }
}