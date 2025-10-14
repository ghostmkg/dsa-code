package com.example.numberguess;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    private int randomNumber;
    private EditText inputGuess;
    private TextView resultText;
    private Button guessBtn, resetBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        inputGuess = findViewById(R.id.inputGuess);
        resultText = findViewById(R.id.resultText);
        guessBtn = findViewById(R.id.guessBtn);
        resetBtn = findViewById(R.id.resetBtn);

        generateRandomNumber();

        guessBtn.setOnClickListener(v -> checkGuess());
        resetBtn.setOnClickListener(v -> resetGame());
    }

    private void generateRandomNumber() {
        randomNumber = new Random().nextInt(100) + 1; // 1–100
    }

    private void checkGuess() {
        String guessStr = inputGuess.getText().toString();
        if (guessStr.isEmpty()) {
            resultText.setText("Please enter a number!");
            return;
        }

        int guess = Integer.parseInt(guessStr);
        if (guess < randomNumber) {
            resultText.setText("Too low! Try again.");
        } else if (guess > randomNumber) {
            resultText.setText("Too high! Try again.");
        } else {
            resultText.setText("🎉 Correct! You guessed it!");
        }
    }

    private void resetGame() {
        inputGuess.setText("");
        resultText.setText("Game reset. Guess again!");
        generateRandomNumber();
    }
}
