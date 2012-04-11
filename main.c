/*
 * FrameChain is a program that takes a lot of snapshots from videos,
 * which is useful for micromotion study and SIMO chart preparation. 
 *  
 * Written by Thomas Abraham <methomasabraham@gmail.com>
 *
 * Copyright (C) 2012, Thomas Abraham.
 * All Rights Reserved.
 */

/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cv.h"
#include "highgui.h"
CvCapture* g_capture = NULL;
void makesnapname(char s[],int i);
int main( int argc, char** argv ) {
  char snapname[15];
  unsigned long int imgno;
  g_capture = cvCreateFileCapture( argv[1] );
  int frames = (int) cvGetCaptureProperty(
					  g_capture,
					  CV_CAP_PROP_FRAME_COUNT
					  );
  IplImage* frame;
  imgno=0;
  while(1) {
    frame = cvQueryFrame( g_capture );
    if( !frame ) 
      break;
    frames = (int) cvGetCaptureProperty(
    					g_capture,
					CV_CAP_PROP_FRAME_COUNT
					); 
    makesnapname(snapname,++imgno);
    cvSaveImage(snapname,frame,0);
  }
  cvReleaseCapture( &g_capture );
  return(0);
}
void makesnapname(char s[],int i){
  int j;
  for(j=9;i>0;i/=10)
    s[j--]=(i%10)+'0';
  while(j)
    s[j--]='0';
  s[0]='I';
  s[10]='.';
  s[11]='j';
  s[12]='p';
  s[13]='g';
  s[14]='\0';
}
