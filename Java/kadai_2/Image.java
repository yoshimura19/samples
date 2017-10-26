import java.awt.image.*;
import java.io.*;
import javax.imageio.*;

public class Image {
    Pixel[][] pixels;    // 3つのインスタンス変数
    int width;
    int height;
    public static void main(String[] args){
        Image image = new Image();
        try{
            image.readImageFile("input.bmp");
            // ここで何か画像処理をする。
            // image.negativeImage();
            // image.grayScale();
            // image.binaraization(100);
            image.averageFilter();
            image.histogramRed();
            image.writeImageFile("output.bmp");
        }catch(IOException error){
            System.out.println("IOエラー発生");
        }
    }
    void readImageFile(String filename) throws IOException{
        BufferedImage bufImage = ImageIO.read(new File(filename));
        width = bufImage.getWidth();
        height = bufImage.getHeight();
        pixels = new Pixel[width][height];
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                pixels[i][j] = new Pixel(bufImage.getRGB(i,j));
            }
        }
    }
    int[] histogramRed() {           // 画素の性質を表すヒストグラム
        int[] hist = new int[256];
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                Pixel p = pixels[i][j];
                hist[p.red]++;
            }
        }
        for(int i = 0; i < 256; i++){
            System.out.println(i+"\t"+hist[i]);
        }
        return hist;
    }
    void binaraization(int threshold) {  // ２値化
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                Pixel p = pixels[i][j];
                int k = 0;
                if(p.red >= threshold){
                    k = 255;
                }
                p.setRGB(k, k, k);
            }
        }
    }
    void averageFilter() {   // 平均化フィルタ(ぼやけるbutノイズを消すため)
        int[][] postfilter = new int[width][height];
        for(int i = 1; i < width; i++) {
            for(int j = 1; j < height; j++) {
                postfilter[i][j] = (pixels[i-1][j-1].red + pixels[i][j-1].red + pixels[i+1][j-1].red +
                                    pixels[i-1][j].red + pixels[i][j].red + pixels[i+1][j].red +
                                    pixels[i-1][j+1].red + pixels[i][j+1].red + pixels[i+1][j+1].red) / 9;
            }
        }
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                pixels[i][j].setRGB(postfilter[i][j], postfilter[i][j], postfilter[i][j]);
            }
        }
    }

    void negativeImage() {             // ネガポジ変換のメソッド
        for(int i=0; i < width; i++) {
            for(int j = 0; j < height; j++) {
                Pixel p = pixels[i][j];
                pixels[i][j].setRGB(0xff-p.red, 0xff-p.green, 0xff-p.blue);
            }
        }
    }
    void grayScale() {               // グレースケール
        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++) {
                Pixel p = pixels[i][j];
                int gray = (p.red + p.green + p.blue) / 3;
                pixels[i][j].setRGB(gray, gray, gray);
            }
        }
    }

    void writeImageFile(String filename) throws IOException{
        BufferedImage bufImage = new BufferedImage(width,height,BufferedImage.TYPE_INT_RGB);
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                bufImage.setRGB(i, j, pixels[i][j].returnARGB());
            }
        }
        ImageIO.write(bufImage, "bmp", new File(filename));
    }
}

class Pixel{
    int alpha;           // 4つの画素値
    int red;
    int green;
    int blue;
    Pixel(int argb){             // (コンストラクタ)4ビットを8バイトづつに分けて、alphaは一般に画像の透明度
        blue = (argb & 0xff);
        green = (argb>>8 & 0xff);
        red = (argb>>16 & 0xff);
        alpha = (argb>>24);
    }
    void setRGB(int r, int g, int b){
        red = r;
        green = g;
        blue = b;
    }
    int returnARGB(){
        return (alpha<<24|red<<16|green<<8|blue);
    }
}
