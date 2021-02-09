package com.example.androidlifecycle;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        Toast.makeText(this, "Second onCreate", Toast.LENGTH_SHORT).show();
        Log.i("SecondActivity", "Second onCreate");
    }

    @Override
    protected void onStart() {
        super.onStart();
        Toast.makeText(this, "Second onStart", Toast.LENGTH_SHORT).show();
        Log.i("SecondActivity", "Second onStart");
    }

    @Override
    protected void onResume() {
        super.onResume();
        Toast.makeText(this, "Second onResume", Toast.LENGTH_SHORT).show();
        Log.i("SecondActivity", "Second onResume");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Toast.makeText(this, "Second onPause", Toast.LENGTH_SHORT).show();
        Log.i("SecondActivity", "Second onPause");
    }

    @Override
    protected void onStop() {
        super.onStop();
        Toast.makeText(this, "Second onStop", Toast.LENGTH_SHORT).show();
        Log.i("SecondActivity", "Second onStop");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Toast.makeText(this, "Second onRestart", Toast.LENGTH_SHORT).show();
        Log.i("SecondActivity", "Second onRestart");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Toast.makeText(this, "Second onDestroy", Toast.LENGTH_SHORT).show();
        Log.i("SecondActivity", "Second onDestroy");
    }
}