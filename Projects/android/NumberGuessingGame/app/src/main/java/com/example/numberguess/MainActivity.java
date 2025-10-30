package com.example.numberguess;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    private int randomNumber;
    private int guessCount = 0;
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

        // Disable guess button until input is provided
        guessBtn.setEnabled(false);
        inputGuess.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                guessBtn.setEnabled(!s.toString().trim().isEmpty());
            }

            @Override
            public void afterTextChanged(Editable s) {}
        });

        guessBtn.setOnClickListener(v -> checkGuess());
        resetBtn.setOnClickListener(v -> resetGame());
    }

    private void generateRandomNumber() {
        randomNumber = new Random().nextInt(100) + 1; // Range: 1–100
    }

    private void showMessage(String message) {
        resultText.setText(message);
    }

    private void checkGuess() {
        String guessStr = inputGuess.getText().toString();

        if (guessStr.isEmpty()) {
            showMessage("Please enter a number!");
            return;
        }

        int guess = Integer.parseInt(guessStr);

        // Range validation
        if (guess < 1 || guess > 100) {
            showMessage("Please enter a number between 1 and 100!");
            return;
        }

        guessCount++;

        if (guess < randomNumber) {
            showMessage("Too low! Try again. (Attempts: " + guessCount + ")");
        } else if (guess > randomNumber) {
            showMessage("Too high! Try again. (Attempts: " + guessCount + ")");
        } else {
            showMessage("🎉 Correct! You guessed it in " + guessCount + " attempts!");
        }
    }

    private void resetGame() {
        inputGuess.setText("");
        guessCount = 0;
        generateRandomNumber();
        showMessage("Game reset! Try to guess again.");
        Toast.makeText(this, "🔁 New number generated!", Toast.LENGTH_SHORT).show();
    }
}
