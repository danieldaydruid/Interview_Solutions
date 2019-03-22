namespace Stock_Info {
    using System;
    using System.Collections.Generic;
    using System.Globalization;
    using Newtonsoft.Json;
    using Newtonsoft.Json.Converters;
    public partial class StockData {
        [JsonProperty("Meta Data")]
        public MetaData MetaData { get; set; }
        [JsonProperty("Time Series (Daily)")]
        public Dictionary<string, TimeSeriesDaily> TimeSeriesDaily { get; set; }
    }
    public partial class MetaData {
        [JsonProperty("1. Information")]
        public string The_Information { get; set; }
        [JsonProperty("2. Symbol")]
        public string The_Symbol { get; set; }
        [JsonProperty("3. Last Refreshed")]
        public DateTimeOffset The3LastRefreshed { get; set; }
        [JsonProperty("4. Output Size")]
        public string The_Output_Size { get; set; }
        [JsonProperty("5. Time Zone")]
        public string The_Time_Zone { get; set; }
    }
    public partial class TimeSeriesDaily {
        [JsonProperty("1. open")]
        public string The_Open { get; set; }

        [JsonProperty("2. high")]
        public string The_High { get; set; }

        [JsonProperty("3. low")]
        public string The_Low { get; set; }

        [JsonProperty("4. close")]
        public string The_Close { get; set; }

        [JsonProperty("5. volume")]
        [JsonConverter(typeof(ParseStringConverter))]
        public long The_Volume { get; set; }
    }
    public partial class StockData { public static StockData FromJson(string json) => JsonConvert.DeserializeObject<StockData>(json, Stock_Info.Converter.Settings); }
    public static class Serialize { public static string ToJson(this StockData self) => JsonConvert.SerializeObject(self, Stock_Info.Converter.Settings); }
    internal static class Converter {
        public static readonly JsonSerializerSettings Settings = new JsonSerializerSettings {
            MetadataPropertyHandling = MetadataPropertyHandling.Ignore,
            DateParseHandling = DateParseHandling.None,
            Converters = { new IsoDateTimeConverter { DateTimeStyles = DateTimeStyles.AssumeUniversal } },
        };
    }
    internal class ParseStringConverter : JsonConverter {
        public override bool CanConvert(Type t) => t == typeof(long) || t == typeof(long?);
        public override object ReadJson(JsonReader reader, Type t, object existingValue, JsonSerializer serializer) {
            if (reader.TokenType == JsonToken.Null) return null;
            var value = serializer.Deserialize<string>(reader);
            long l;
            if (Int64.TryParse(value, out l)) {
                return l;
            }
            throw new Exception("Cannot unmarshal type long");
        }
        public override void WriteJson(JsonWriter writer, object untypedValue, JsonSerializer serializer) {
            if (untypedValue == null) {
                serializer.Serialize(writer, null);
                return;
            }
            var value = (long)untypedValue;
            serializer.Serialize(writer, value.ToString());
            return;
        }
        public static readonly ParseStringConverter Singleton = new ParseStringConverter();
    }
}