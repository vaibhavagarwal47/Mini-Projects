import requests, json

city = input('Enter your city: ')
url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid=3265874a2c77ae4a04bb96236a642d2f"
temp_f = requests.get(url).json()

print(f'''
            Temperature: {round(temp_f['main']['temp']-273)},
            longitude: {temp_f['coord']['lon']},
            latitude: {temp_f['coord']['lat']},
            description: {temp_f['weather'][0]['description']},
            feels_like: {round(temp_f['main']['feels_like']-273)},
            temp_min: {round(temp_f['main']['temp_min']-273)},
            temp_max: {round(temp_f['main']['temp_max']-273)},
            pressure: {temp_f['main']['pressure']},
            humidity: {temp_f['main']['humidity']},
            wind: {temp_f['wind']},
            country: {temp_f['sys']['country']},
            sunrise: {temp_f['sys']['sunrise']},
            sunset: {temp_f['sys']['sunset']},
            timezone: {temp_f['timezone']}
      ''')





