#ifndef OpenWeatherMap_h
#define OpenWeatherMap_h

#include <Arduino.h>

#include <ArduinoJson.h>

#include <ESPHTTPClient.h>

#include <WiFiClient.h>

class OpenWeatherMap
{
public:
	OpenWeatherMap(WiFiClient client, String apiKey);

	int getData(String cityId);

	int getTemperature();

	int getHumidity();

	String getCityName();

	String getForecast();

	int getForecastIdx();

	int getPressure();

private:
	int _openTemperature;

	int _openHumidity;

	String _apiString;

	String _openForecast;

	int _openForecastIdx;

	int _openPressure;

	String _cityName;

	WiFiClient client;

	void parseData(DynamicJsonDocument doc);
};

// the #include statment and code go here...

#endif
