package com.example.notesapp;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.content.SharedPreferences;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText notesInput;
    private Button saveBtn, clearBtn;
    private SharedPreferences sharedPreferences;
    private static final String PREFS_NAME = "MyNotesPref";
    private static final String KEY_NOTE = "note";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        notesInput = findViewById(R.id.notesInput);
        saveBtn = findViewById(R.id.saveBtn);
        clearBtn = findViewById(R.id.clearBtn);

        sharedPreferences = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);

        // Load saved note
        String savedNote = sharedPreferences.getString(KEY_NOTE, "");
        notesInput.setText(savedNote);

        // Save note
        saveBtn.setOnClickListener(v -> {
            String note = notesInput.getText().toString();
            sharedPreferences.edit().putString(KEY_NOTE, note).apply();
            Toast.makeText(this, "📝 Note saved!", Toast.LENGTH_SHORT).show();
        });

        // Clear note
        clearBtn.setOnClickListener(v -> {
            notesInput.setText("");
            sharedPreferences.edit().remove(KEY_NOTE).apply();
            Toast.makeText(this, "🗑️ Note cleared!", Toast.LENGTH_SHORT).show();
        });
    }
}
