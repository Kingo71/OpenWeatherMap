# OpenWeatherMap

ESP32 OpenWeatherMap library

# Usage

OpenWeatherMap weather(WiFiClient client, String apiKey);

# Methods

## .getData(String cityID)

return GET server response.

## .getTemperature()

return Selected city temperature.

## .getCityName()

return Selected City name.

## .getHumidity()

return Selected City humidity.

## .getPressure()

return Selected City pressure.

## .getForecast()

return Selected City forecast description.

## .getForecastIdx()

return Selected City forecast icon index.
