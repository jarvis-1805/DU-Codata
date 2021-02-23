package com.example.intentimplicit;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button send;
        EditText edtTxt;

        send = findViewById(R.id.sendButton);
        edtTxt = findViewById(R.id.editText);

        send.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String data = edtTxt.getText().toString();
                if(!data.equals("")) {
                    Intent sendIntent = new Intent();
                    sendIntent.setAction(Intent.ACTION_SEND);
                    sendIntent.setType("text/plain");
                    sendIntent.putExtra(Intent.EXTRA_TEXT, data);
                    startActivity(sendIntent);
                } else{
                    edtTxt.setError("Please enter data!");
                }
            }
        });
    }
}