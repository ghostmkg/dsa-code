package com.example.simplecounter;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private int count = 0;
    private TextView counterText;
    private Button incrementBtn, resetBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        counterText = findViewById(R.id.counterText);
        incrementBtn = findViewById(R.id.incrementBtn);
        resetBtn = findViewById(R.id.resetBtn);

        incrementBtn.setOnClickListener(v -> {
            count++;
            counterText.setText(String.valueOf(count));
        });

        resetBtn.setOnClickListener(v -> {
            count = 0;
            counterText.setText(String.valueOf(count));
        });
    }
}
