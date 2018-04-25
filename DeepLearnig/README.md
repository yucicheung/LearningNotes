# 不平衡数据集的迁移学习
针对小数据集和不平衡数据集的深度学习。
## 数据增广方法
数据增广通常不改变数据集的content，但是可以增加数据的diverdity和模型的generalization performance。常用的数据增广方法：
- 增加噪声
- 旋转
- 平移
- 镜像
- scaling
等

计算机视觉有七类分类问题： 
不同的视角，不同的大小，物体的形变问题，物体的遮挡问题，光照条件，背景复杂的问题，每一类中有多种形态的问题。 
而数据增广的思路也就是解决这个问题。数据增广如何增广就要从实际的问题出发，比如医学的图片基本上拍摄的时候视角是固定的，所以就不需要不同视角的增广。

2、data augmentation常用方法

Color Jittering：对颜色的数据增强：图像亮度、饱和度、对比度变化（此处对色彩抖动的理解不知是否得当）；
PCA  Jittering：首先按照RGB三个颜色通道计算均值和标准差，再在整个训练集上计算协方差矩阵，进行特征分解，得到特征向量和特征值，用来做PCA Jittering；
Random Scale：尺度变换；
Random Crop：采用随机图像差值方式，对图像进行裁剪、缩放；包括Scale Jittering方法（VGG及ResNet模型使用）或者尺度和长宽比增强变换；
Horizontal/Vertical Flip：水平/垂直翻转；
Shift：平移变换；
Rotation/Reflection：旋转/仿射变换；
Noise：高斯噪声、模糊处理；
Label shuffle：类别不平衡数据的增广，参见海康威视ILSVRC2016的report；另外，文中提出了一种Supervised Data Augmentation方法，有兴趣的朋友的可以动手实验下。

数据增强对最后的识别性能和泛化能力都有着非常重要的作用。我们使用下面这些数据增强方法。第一，对颜色的数据增强，包括色彩的饱和度、亮度和对比度等方面，主要从Facebook的代码里改过来的。第二，PCA Jittering，最早是由Alex在他2012年赢得ImageNet竞赛的那篇NIPS中提出来的. 我们首先按照RGB三个颜色通道计算了均值和标准差，对网络的输入数据进行规范化，随后我们在整个训练集上计算了协方差矩阵，进行特征分解，得到特征向量和特征值，用来做PCA Jittering。第三，在图像进行裁剪和缩放的时候，我们采用了随机的图像差值方式。第四， Crop Sampling，就是怎么从原始图像中进行缩放裁剪获得网络的输入。比较常用的有2种方法：一是使用Scale Jittering，VGG和ResNet模型的训练都用了这种方法。二是尺度和长宽比增强变换，最早是Google提出来训练他们的Inception网络的。我们对其进行了改进，提出Supervised Data Augmentation方法。

