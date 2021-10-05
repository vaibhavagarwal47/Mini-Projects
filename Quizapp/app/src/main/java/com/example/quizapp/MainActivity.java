package com.example.quizapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.material.badge.BadgeUtils;

public class MainActivity extends AppCompatActivity {
    private String[] questions = {"Java is a person?","Java was introduced in 1233?","Java was created using python?",
            "Java has abstract classes?","java supports interfaces?"};
    private boolean[] answers = {false,false,false,true,true};
    private int score=0;
    private int index = 0;
    Button yes,no;
    TextView question;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        yes = findViewById(R.id.Yes);
        no = findViewById(R.id.No);
        question = findViewById(R.id.question);
        question.setText(questions[index]);
        yes.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view)
            {
                if(index<=questions.length-1)
                {
                    if(answers[index]==true)
                    {
                        score++;
                    }
                    index++;
                    if(index <= questions.length-1)
                    {
                        question.setText(questions[index]);
                    }
                    else
                        Toast.makeText(MainActivity.this, "Final score is: " +score+"/"+questions.length, Toast.LENGTH_SHORT).show();
                }
            }
        });

        no.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view)
            {
                //if array is n
                if(index<=questions.length-1)
                {
                    if(answers[index]==false)
                    {
                        score++;
                    }
                    index++;
                    if(index<=questions.length-1)
                    {
                        question.setText(questions[index]);
                    }
                    else
                        Toast.makeText(MainActivity.this, "Final score is:"+score+"/"+questions.length, Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}