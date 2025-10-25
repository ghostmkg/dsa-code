# RandomForest is used for classification Problems and recommendation systems
import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier

# Step 1: Create a sample dataset in a dictionary
# This data represents movies with their attributes.
data = {
    'ratings': [9, 2, 8, 3, 7, 4, 1, 5, 9, 2, 9, 8],
    'price': [250, 200, 150, 200, 300, 350, 250, 600, 450, 500, 300, 280],
    'watchTime': [2, 3, 2, 4, 2, 1, 2, 3, 2, 3, 2, 2.5],
    'genre': ["Action", "Comedy", "Sci-Fi", "Thriller", "Documentary", "Action", "Sci-Fi", "Romantic", "Comedy", "Suspense", "Horror", "Action"],
    'Suggested_Movie': ['The Dark Knight', 'Superbad', 'Blade Runner', 'The Silence of the Lambs', 'Planet Earth', 'John Wick', 'Arrival', 'The Notebook', 'Step Brothers', 'The Sixth Sense', 'The Conjuring', 'Mad Max: Fury Road']
}
df = pd.DataFrame(data)

# Step 2: Preprocess the data
# Machine learning models need numerical data, so we convert text (like genre) into numbers.

# Encode the 'genre' feature
genre_encoder = LabelEncoder()
df['genre_encoded'] = genre_encoder.fit_transform(df['genre'])

# Encode the 'Suggested_Movie' target variable
movie_encoder = LabelEncoder()
df['Movie_Label'] = movie_encoder.fit_transform(df['Suggested_Movie'])

# Step 3: Define Features (X) and Target (Y)
# Features are the inputs used for prediction.
X = df[['ratings', 'price', 'watchTime', 'genre_encoded']]
# Target is the output we want to predict.
Y = df['Movie_Label']

# Step 4: Split data into training and testing sets
# We train the model on 80% of the data and test its performance on the remaining 20%.
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.2, random_state=42)

# Step 5: Train the RandomForest model
# The model learns the relationship between the features and the movie label.
model = RandomForestClassifier(n_estimators=100, random_state=42)
model.fit(X_train, y_train)

# Step 6: Predict a movie for a new user
# Let's say a user wants an "Action" movie with a high rating.
# We must encode the user's genre preference ("Action") the same way we did for the training data.
try:
    action_genre_code = genre_encoder.transform(["Action"])[0]
    
    # New user's preferences: [rating, price, watchTime, genre]
    new_user_preferences = [[9, 300, 2.5, action_genre_code]]

    # Predict the movie label for the new user
    predicted_label = model.predict(new_user_preferences)

    # Convert the predicted label back to the actual movie name
    predicted_movie = movie_encoder.inverse_transform(predicted_label)

    print(f"Based on your preferences, we recommend: {predicted_movie[0]}")

except ValueError:
    print("The genre 'Action' was not found in the training data. Please choose from available genres.")
