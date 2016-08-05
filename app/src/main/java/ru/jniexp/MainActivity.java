package ru.jniexp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("nonograms_model");
    }

    public native String encrypt(String plainText);
    public native String decrypt(String ciphertext);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String inputText = "Some Text";
        String s1 = encrypt(inputText);
        String s2 = decrypt(s1);
        int x = 0;
    }
}
