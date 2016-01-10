package com.han.jm.activitylifecycletest;

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
public class MainActivity extends Activity {
	public static final String TAG = "MainActivity";

	@Override
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		Log.d(TAG, "onCreate");
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.activity_main);

		if(savedInstanceState != null){
			String tmpData = savedInstanceState.getString("data_key");
			Log.d(TAG, tmpData);
		}

		Button startNormalActivity = (Button) findViewById(R.id.start_normal_activity);
		Button startDialogActivity = (Button) findViewById(R.id.start_dialog_activity);
		startNormalActivity.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(MainActivity.this, NormalActivity.class);
				startActivity(intent);
			}
		});
		startDialogActivity.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(MainActivity.this, DialogActivity.class);
				startActivity(intent);
			}
		});
	}

	@Override
	protected void onStart(){
		super.onStart();
		Log.d(TAG, "onStart");
	}

	@Override
	protected void onResume(){
		super.onResume();
		Log.d(TAG, "onResume");
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

	@Override
	protected void onRestart(){
		super.onRestart();
		Log.d(TAG, "onRestart");
	}

	@Override
	protected void onSaveInstanceState(Bundle outState){
		super.onSaveInstanceState(outState);
		String tmpData = "Sth you just typed";
		outState.putString("data_key", tmpData);
	}
}
