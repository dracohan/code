package c11;/**
 * @project: LearningJava
 * @filename: CalendarTest.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 8:35 2015/7/27
 * @comment: Test Purpose
 * @result:
 */

import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.TimeZone;

import static tool.util.prt;

public class CalendarTest {
    public static void main(String[] args) {
        Calendar cal = Calendar.getInstance();
        prt(cal.getTime());

        GregorianCalendar now = new GregorianCalendar();
        prt(now.getTime());

        Date date = new Date();
        prt(date.getTime());
        //below func also call date.gettime
        prt(System.currentTimeMillis());

        String[] tz = TimeZone.getAvailableIDs();
        //for(int i = 0; i < tz.length; i++)
        //    prt(tz[i]);

        TimeZone LAN = TimeZone.getTimeZone("America/Los_Angeles");
        Calendar usa = Calendar.getInstance(LAN);
        usa.setTime(date);
        prt(usa.get(Calendar.DAY_OF_WEEK));
        prt(usa.getTime());

        TimeZone CHN = TimeZone.getTimeZone("GMT+08");
        Calendar china = Calendar.getInstance(CHN);
        china.setTime(date);
        prt(china.get(Calendar.DAY_OF_WEEK));
        prt(usa.getTime());

    }
}
