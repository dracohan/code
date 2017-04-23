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
	public static String TAG = "SecondActivity";
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		//check the instance of FirstActivity
		Log.d(TAG, this.toString());
		Log.d(TAG, "Task id is " + getTaskId());

		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.second_layout);
		Intent  intent = getIntent();
		//String data = intent.getStringExtra("extra_data");
//		Bundle b = intent.getExtras();
		Bundle b = intent.getBundleExtra("data");
		if (b != null){
			String str = b.getString("str_key");
			//TODO: transfer string and int with bundle failed
			Integer i = b.getInt("int_key");
			Log.d("SecondActivity", String.format("str_key=%s, int_key=%d", str, i));
			//Log.d("SecondActivity", i.toString());
		}


		Button button2 = (Button) findViewById(R.id.button_2);
		button2.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Log.d("SecondActivity", "Button 2 clicked.");
/*				Intent intent = new Intent();
				intent.putExtra("data_return", "Hello FirstActivity");
				setResult(RESULT_OK, intent);
				finish();*/
				Intent intent = new Intent(SecondActivity.this, FirstActivity.class);
				startActivity(intent);
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

	@Override
	protected void onPause(){
		super.onPause();
		Log.d(TAG, "onPause");
	}

	@Override
	protected void onStop(){
		super.onStop();
		Log.d(TAG, "onStop");
	}

	@Override
	protected void onDestroy(){
		super.onDestroy();
		Log.d(TAG, "onDestroy");
	}

}
