#include "OpenWeatherMap.h"

const char *root_ca =
	"-----BEGIN CERTIFICATE-----\n"
	"MIIFZTCCBE2gAwIBAgIRALzs5v3uLgXTRv5sxpMwnu8wDQYJKoZIhvcNAQELBQAw\n"
	"gZAxCzAJBgNVBAYTAkdCMRswGQYDVQQIExJHcmVhdGVyIE1hbmNoZXN0ZXIxEDAO\n"
	"BgNVBAcTB1NhbGZvcmQxGjAYBgNVBAoTEUNPTU9ETyBDQSBMaW1pdGVkMTYwNAYD\n"
	"VQQDEy1DT01PRE8gUlNBIERvbWFpbiBWYWxpZGF0aW9uIFNlY3VyZSBTZXJ2ZXIg\n"
	"Q0EwHhcNMTgwMzE1MDAwMDAwWhcNMjAwMzIxMjM1OTU5WjBiMSEwHwYDVQQLExhE\n"
	"b21haW4gQ29udHJvbCBWYWxpZGF0ZWQxHjAcBgNVBAsTFUVzc2VudGlhbFNTTCBX\n"
	"aWxkY2FyZDEdMBsGA1UEAwwUKi5vcGVud2VhdGhlcm1hcC5vcmcwggEiMA0GCSqG\n"
	"SIb3DQEBAQUAA4IBDwAwggEKAoIBAQDtaNLwzs/kV/bfFFN5AQ+gC2nAy1mS8cG3\n"
	"TIIkxMn/xI9x48gy//b7lVsijMvtubvhNrqhEZluHwO0/dcT58rjaL7lpKw9Ilsv\n"
	"jxuEIdgykUA8RbsvKsTw6EUPdQSq6YKQZco2r+wT8+1tmnAnInfdyDfBAB+RyTzG\n"
	"6tFmzhBN4z5/JMP/xyGT9AnU12Fb6BbEV0WrowvkU++DlCE6PgVQr46ztCeOX+uV\n"
	"X2O5XYktOufxckuMNJk0PVCisNmBiTfLrE/zm+kJJu1ydVuSQ59D/mGXQ95P51f7\n"
	"P6Bq8eqg+765YlNpFPpRR4I8zRFmgSCc3cnvNFe/NisacpOY94b9AgMBAAGjggHl\n"
	"MIIB4TAfBgNVHSMEGDAWgBSQr2o6lFoL2JDqElZz30O0Oija5zAdBgNVHQ4EFgQU\n"
	"07lrspL7/M6BX6dY9qJ43nnE/V0wDgYDVR0PAQH/BAQDAgWgMAwGA1UdEwEB/wQC\n"
	"MAAwHQYDVR0lBBYwFAYIKwYBBQUHAwEGCCsGAQUFBwMCME8GA1UdIARIMEYwOgYL\n"
	"KwYBBAGyMQECAgcwKzApBggrBgEFBQcCARYdaHR0cHM6Ly9zZWN1cmUuY29tb2Rv\n"
	"LmNvbS9DUFMwCAYGZ4EMAQIBMFQGA1UdHwRNMEswSaBHoEWGQ2h0dHA6Ly9jcmwu\n"
	"Y29tb2RvY2EuY29tL0NPTU9ET1JTQURvbWFpblZhbGlkYXRpb25TZWN1cmVTZXJ2\n"
	"ZXJDQS5jcmwwgYUGCCsGAQUFBwEBBHkwdzBPBggrBgEFBQcwAoZDaHR0cDovL2Ny\n"
	"dC5jb21vZG9jYS5jb20vQ09NT0RPUlNBRG9tYWluVmFsaWRhdGlvblNlY3VyZVNl\n"
	"cnZlckNBLmNydDAkBggrBgEFBQcwAYYYaHR0cDovL29jc3AuY29tb2RvY2EuY29t\n"
	"MDMGA1UdEQQsMCqCFCoub3BlbndlYXRoZXJtYXAub3JnghJvcGVud2VhdGhlcm1h\n"
	"cC5vcmcwDQYJKoZIhvcNAQELBQADggEBAC7670dDCFEhHWf5haPB3nBeK5IUL3G3\n"
	"igSTSGmSWm5NI+0EuwH+pDLRG5PeJWaWq1ZswOYvR3wp82DeCH307Cj1O4FxPm54\n"
	"6W+CLGkrXC1eMq9HFXs+uzxNoAFZY21QokbiGDiZybN7HUvdtYbkW75rcrIUToTf\n"
	"j/vESBKqfoRPx2bxS661RxuMlkpJOoqBQA+B7wjOPvamS+GHgWc54ugl0V3P4w+B\n"
	"pB5S3f7Esbo1CWXaMwKFwzM1yToMDWGqJaZ9uDTxKnUfzBu5PplXlGY/2+CyQ0eq\n"
	"uJrCdycdDUwhdEYj5n+EJjhiXnmzmIHyQX2Yhk+hVc7XhzRIsmw4lNk=\n"
	"-----END CERTIFICATE-----\n";

#define API_CMD "https://api.openweathermap.org/data/2.5/weather?id="

String _apiKey;

String _apiString;

int _openTemperature;

int _openHumidity;

int _openPressure;

String _cityName;

String _openForecast;

int _openForecastIdx;

OpenWeatherMap::OpenWeatherMap(WiFiClient client, String apiKey)
{
	_apiKey = apiKey;
}

int OpenWeatherMap::getTemperature()
{

	return _openTemperature;
}

int OpenWeatherMap::getHumidity()
{

	return _openHumidity;
}

String OpenWeatherMap::getForecast()
{

	return _openForecast;
}

int OpenWeatherMap::getForecastIdx()
{

	return _openForecastIdx;
}

int OpenWeatherMap::getPressure()
{

	return _openPressure;
}

String OpenWeatherMap::getCityName()
{

	return _cityName;
}

// getData() , return HTTP_CODE

int OpenWeatherMap::getData(String cityId)
{

	_apiString = API_CMD + cityId + String("&APPID=") + _apiKey + String("&units=metric");

	DynamicJsonDocument _doc(2048);

	HTTPClient http;

	http.begin(_apiString, root_ca);
	// start connection and send HTTP header
	int httpCode = http.GET();

	// httpCode will be negative on error
	if (httpCode > 0)
	{

		// HTTP header has been send and Server response header has been handled
		// file found at server

		if (httpCode == HTTP_CODE_OK)
		{
			String payload = http.getString();
			deserializeJson(_doc, payload);
			parseData(_doc);
		}
	}

	http.end();

	return httpCode;
}

void OpenWeatherMap::parseData(DynamicJsonDocument doc)
{

	_cityName = doc["name"].as<char *>();
	_openTemperature = doc["main"]["temp"];
	_openHumidity = doc["main"]["humidity"];
	_openForecastIdx = doc["weather"]["id"];
	_openForecast = doc["weather"]["description "].as<char *>();
	_openPressure = doc["main"]["pressure"];
}
