package com.example.spinningspinner;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Spinner spinner = findViewById(R.id.spinner);
        ImageView image = findViewById(R.id.imageView);

        String[] mark = {"Select One", "MARK I", "MARK VI", "MARK XLII", "MARK XLIV", "WMA MARK I"};

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_selectable_list_item, mark);

        spinner.setAdapter(adapter);
    }
}