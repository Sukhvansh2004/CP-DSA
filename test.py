from geopy.geocoders import Nominatim

# Initialize Nominatim geocoder
geolocator = Nominatim(user_agent="geoapiExercises")

# Coordinates (latitude, longitude)
coordinates = "27.9879°, 86.9253°"

# Using reverse method
location = geolocator.reverse(coordinates)

print(location.address)
