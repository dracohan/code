package c10;

import java.io.File;

/**
 * Created by root on 6/10/15.
 */
public interface FilenameFilter {
    boolean accept(File dir, String str);
}
