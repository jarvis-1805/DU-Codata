package com.example.intentexplicit;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;


public class SecondActivity extends AppCompatActivity {

    TextView txtView;
    String data;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        txtView = findViewById(R.id.tv4);

        Intent intent = getIntent();
        data = intent.getStringExtra("Data");
        if(!data.equals("")){
            txtView.setText(data);
        }
        else{
            txtView.setText(R.string.Null);
        }
    }
}