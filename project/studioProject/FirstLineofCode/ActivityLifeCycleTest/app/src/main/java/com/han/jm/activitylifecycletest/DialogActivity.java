package com.han.jm.activitylifecycletest;

import android.app.Activity;
import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.Window;

/**
 * Created by JM on 2016/1/10.
 */
public class DialogActivity extends Activity {
	private static final String TAG = "DialogActivity";

	@Override
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		Log.d(TAG, "onCreate");
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.dialog_layout);
	}

	@Override
	public void onAttachFragment(Fragment fragement){
		super.onAttachFragment(fragement);
		Log.d(TAG, "onAttachFragment");
	}

	@Override
	public void onContentChanged(){
		super.onContentChanged();
		Log.d(TAG, "onContentChanged");
	}

	@Override
	protected void onStart(){
		super.onStart();
		Log.d(TAG, "onStart");
	}

	@Override
	protected void onRestoreInstanceState(Bundle outState){
		super.onRestoreInstanceState(outState);
		Log.d(TAG, "onRestoreInstanceState");
	}

	@Override
	protected void onPostCreate(Bundle outState){
		super.onPostCreate(outState);
		Log.d(TAG, "onPostCreate");
	}

	@Override
	protected void onResume(){
		super.onResume();
		Log.d(TAG, "onResume");
	}

	@Override
	protected void onPostResume(){
		super.onPostResume();
		Log.d(TAG, "onPostResume");
	}

	@Override
	public void onAttachedToWindow (){
		super.onAttachedToWindow();
		Log.d(TAG, "onAttachedToWindow");
	}

	@Override
	public boolean onCreateOptionsMenu (Menu menu){
		super.onCreateOptionsMenu(menu);
		Log.d(TAG, "onCreateOptionsMenu");
		return true;
	}

	@Override
	public boolean onPrepareOptionsMenu (Menu menu){
		super.onPrepareOptionsMenu(menu);
		Log.d(TAG, "onPrepareOptionsMenu");
		return true;
	}

	@Override
	protected void onPause(){
		super.onPause();
		Log.d(TAG, "onPause");
	}

	@Override
	protected void onSaveInstanceState(Bundle outState){
		super.onSaveInstanceState(outState);
		Log.d(TAG, "onSaveInstanceState");
		String tmpData = "Sth you just typed generate from onSaveInstanceState";
		outState.putString("data_key", tmpData);
	}

	@Override
	protected void onStop(){
		super.onStop();
		Log.d(TAG, "onStop");
	}

	@Override
	protected void onRestart(){
		super.onRestart();
		Log.d(TAG, "onRestart");
	}

	@Override
	protected void onDestroy(){
		super.onDestroy();
		Log.d(TAG, "onDestroy");
	}

}
