package com.han.jm.activitytest;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.widget.Button;
import android.widget.Toast;

/**
 * Created by JM on 2016/1/8.
 */
public class FirstActivity extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.first_layout);

		//Toast
		Button button1 = (Button) findViewById(R.id.button_1);
		button1.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Toast.makeText(FirstActivity.this, "You clicked Button 1",
						Toast.LENGTH_SHORT).show();
			}
		});

		Button button11 = (Button) findViewById(R.id.button_11);
		button11.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				finish();
			}
		});
		Button button12 = (Button) findViewById(R.id.button_12);
		button12.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent(FirstActivity.this, SecondActivity.class);
				String data = "Hello SecondActivity";
				intent.putExtra("extra_data", data);
				startActivity(intent);
			}
		});

		Button button13 = (Button) findViewById(R.id.button_13);
		button13.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Log.e("FirstActivity", "Send implicit Intent");
				Intent intent = new Intent("com.han.jm.activitytest.ACTION_START");
				String data = "Hello SecondActivity";
				intent.putExtra("extra_data", data);
				startActivityForResult(intent, 1);
			}
		});


		Button button14 = (Button) findViewById(R.id.button_14);
		button14.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent("com.han.jm.activitytest.ACTION_START");
				intent.addCategory("com.han.jm.activitytest.MY_CATEGORY");
				startActivity(intent);
			}
		});

		Button button15 = (Button) findViewById(R.id.button_15);
		button15.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				Intent intent = new Intent("Intent.ACTION_DIAL");
				intent.setData(Uri.parse("tel:10086"));
				startActivity(intent);
			}
		});
	}

	public boolean onCreateOptionsMenu(Menu menu){
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	public boolean onOptionsItemSeleteted(MenuItem item){
		switch (item.getItemId()) {
			case R.id.add_item:
				Toast.makeText(this, "You clicked Add", Toast.LENGTH_SHORT).show();
				break;
			case R.id.remote_item:
				Toast.makeText(this, "You clicked Remove", Toast.LENGTH_SHORT).show();
				break;
			default:
		}
		return true;
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data){
		Log.e("FirstActivity", "Entering onActivityResult");
		switch (requestCode){
			case 1:
				if(resultCode == RESULT_OK){
					String returnedData = data.getStringExtra("data_return");
					Log.e("FirstActivity", returnedData);
				}
				break;
			default:
		}
	}


}
