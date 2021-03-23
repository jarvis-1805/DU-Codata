package com.example.spinningspinner;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Spinner spinner = findViewById(R.id.spinner);
        ImageView image = findViewById(R.id.imageView);
        TextView text = findViewById(R.id.text);

        String[] mark = {"Select One", "MARK I", "MARK VI", "MARK XLII", "MARK XLIV", "WMA MARK I"};

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_selectable_list_item, mark);

        spinner.setAdapter(adapter);

        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                switch (position){
                    case 0:
                        image.setVisibility(View.INVISIBLE);
                        text.setText("");
                        break;
                    case 1:
                        image.setVisibility(View.VISIBLE);
                        image.setImageResource(R.drawable.mark_i);
                        text.setText(R.string.mark_i);
                        break;
                    case 2:
                        image.setVisibility(View.VISIBLE);
                        image.setImageResource(R.drawable.mark_vi);
                        text.setText(R.string.mark_vi);
                        break;
                    case 3:
                        image.setVisibility(View.VISIBLE);
                        image.setImageResource(R.drawable.mark_xlii__mark_42_);
                        text.setText(R.string.mark_xlii);
                        break;
                    case 4:
                        image.setVisibility(View.VISIBLE);
                        image.setImageResource(R.drawable.mark_xliv__hulkbuster_);
                        text.setText(R.string.mark_xliv);
                        break;
                    case 5:
                        image.setVisibility(View.VISIBLE);
                        image.setImageResource(R.drawable.war_machine_armor_mark_i);
                        text.setText(R.string.war_machine_armor_mark_i);
                        break;
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });
    }
}