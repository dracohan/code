package com.han.jm.activitytest;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.widget.Button;

/**
 * Created by JM on 2016/1/10.
 */
public class SecondActivity extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.second_layout);
		Intent  intent = getIntent();
		String data = intent.getStringExtra("extra_data");
		Log.e("SecondActivity", data);

		Button button2 = (Button) findViewById(R.id.button_2);
		button2.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Log.e("SecondActivity", "Button 2 clicked.");
				Intent intent = new Intent();
				intent.putExtra("data_return", "Hello FirstActivity");
				setResult(RESULT_OK, intent);
				finish();
			}
		});
	}

	@Override
	public void onBackPressed(){
		Intent intent = new Intent();
		intent.putExtra("data_return", "Hello FirstActivity with back button");
		setResult(RESULT_OK, intent);
		finish();
	}

}
