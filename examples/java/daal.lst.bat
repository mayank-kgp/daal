@echo off
rem ============================================================================
rem Copyright 2014-2016 Intel Corporation
rem
rem Licensed under the Apache License, Version 2.0 (the "License");
rem you may not use this file except in compliance with the License.
rem You may obtain a copy of the License at
rem
rem     http://www.apache.org/licenses/LICENSE-2.0
rem
rem Unless required by applicable law or agreed to in writing, software
rem distributed under the License is distributed on an "AS IS" BASIS,
rem WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
rem See the License for the specific language governing permissions and
rem limitations under the License.
rem ============================================================================

rem  Content:
rem      Intel(R) Data Analytics Acceleration Library examples list
rem ============================================================================

set Java_example_list=association_rules\AssocRulesAprioriBatch ^
boosting\brownboost\BrownBoostDenseBatch ^
boosting\adaboost\AdaBoostDenseBatch ^
boosting\logitboost\LogitBoostDenseBatch ^
cholesky\CholeskyDenseBatch ^
compression\CompressorExample ^
compression\CompressionBatch ^
compression\CompressionOnline ^
covariance\CovDenseBatch ^
covariance\CovDenseDistr ^
covariance\CovDenseOnline ^
covariance\CovCSRBatch ^
covariance\CovCSRDistr ^
covariance\CovCSROnline ^
datasource\DataStructuresHomogen ^
datasource\DataStructuresHomogenTensor ^
datasource\DataStructuresAOS ^
datasource\DataStructuresSOA ^
datasource\DataStructuresCSR ^
datasource\DataStructuresMerged ^
datasource\DataStructuresMatrix ^
datasource\DataStructuresPackedSymmetric ^
datasource\DataStructuresPackedTriangular ^
distance\CorDistDenseBatch ^
distance\CosDistDenseBatch ^
em\EmGmmDenseBatch ^
kmeans\KMeansDenseBatch ^
kmeans\KMeansCSRBatch ^
kmeans\KMeansDenseDistr ^
kmeans\KMeansCSRDistr ^
linear_regression\LinRegNormEqDenseBatch ^
linear_regression\LinRegNormEqDenseDistr ^
linear_regression\LinRegNormEqDenseOnline ^
linear_regression\LinRegQRDenseBatch ^
linear_regression\LinRegQRDenseDistr ^
linear_regression\LinRegQRDenseOnline ^
moments\LowOrderMomsDenseBatch ^
moments\LowOrderMomsDenseDistr ^
moments\LowOrderMomsDenseOnline ^
moments\LowOrderMomsCSRBatch ^
moments\LowOrderMomsCSRDistr ^
moments\LowOrderMomsCSROnline ^
naive_bayes\MnNaiveBayesDenseBatch ^
naive_bayes\MnNaiveBayesCSRBatch ^
naive_bayes\MnNaiveBayesDenseOnline ^
naive_bayes\MnNaiveBayesDenseDistr ^
naive_bayes\MnNaiveBayesCSROnline ^
naive_bayes\MnNaiveBayesCSRDistr ^
outlier_detection\OutDetectUniDenseBatch ^
outlier_detection\OutDetectMultBaconBatch ^
outlier_detection\OutDetectMultDefaultBatch ^
pca\PCACorDenseBatch ^
pca\PCACorDenseDistr ^
pca\PCACorDenseOnline ^
pca\PCACorCSRBatch ^
pca\PCACorCSRDistr ^
pca\PCACorCSROnline ^
pca\PCASVDDenseBatch ^
pca\PCASVDDenseDistr ^
pca\PCASVDDenseOnline ^
qr\QRDenseBatch ^
qr\QRDenseDistr ^
qr\QRDenseOnline ^
ridge_regression\RidgeRegNormEqDenseBatch ^
ridge_regression\RidgeRegNormEqDenseOnline ^
ridge_regression\RidgeRegNormEqDistr ^
serialization\SerializationExample ^
stump\StumpDenseBatch ^
svd\SVDDenseBatch ^
svd\SVDDenseDistr ^
svd\SVDDenseOnline ^
svm\SVMMultiClassDenseBatch ^
svm\SVMMultiClassCSRBatch ^
svm\SVMTwoClassDenseBatch ^
svm\SVMTwoClassCSRBatch ^
services\LibraryVersionInfoExample ^
quantiles\QuantilesDenseBatch ^
pivoted_qr\PivotedQRDenseBatch ^
quality_metrics\LinRegMetricsDenseBatch ^
quality_metrics\SVMTwoClassMetricsDenseBatch ^
quality_metrics\SVMMultiClassMetricsDenseBatch ^
kernel_function\KernelFuncLinDenseBatch ^
kernel_function\KernelFuncLinCSRBatch ^
kernel_function\KernelFuncRbfDenseBatch ^
kernel_function\KernelFuncRbfCSRBatch ^
implicit_als\ImplAlsCSRBatch ^
implicit_als\ImplAlsCSRDistr ^
implicit_als\ImplAlsDenseBatch ^
set_number_of_threads\SetNumberOfThreads ^
datasource\DataStructuresMerged ^
sorting\SortingDenseBatch ^
error_handling\ErrorHandling ^
math\SoftmaxDenseBatch ^
math\AbsDenseBatch ^
math\AbsCSRBatch ^
math\SmoothReLUDenseBatch ^
math\LogisticDenseBatch ^
math\ReLUCSRBatch ^
math\ReLUDenseBatch ^
math\TanhDenseBatch ^
math\TanhCSRBatch ^
normalization\ZScoreDenseBatch ^
optimization_solvers\MSEDenseBatch ^
optimization_solvers\SGDDenseBatch ^
optimization_solvers\SGDMiniDenseBatch ^
optimization_solvers\LBFGSDenseBatch ^
optimization_solvers\LBFGSOptResDenseBatch ^
optimization_solvers\AdagradDenseBatch ^
optimization_solvers\AdagradOptResDenseBatch ^
neural_networks\ReLULayerDenseBatch ^
neural_networks\AbsLayerDenseBatch ^
neural_networks\DropoutLayerDenseBatch ^
neural_networks\FullyconLayerDenseBatch ^
neural_networks\SplitLayerDenseBatch ^
neural_networks\BatchNormLayerDenseBatch ^
neural_networks\SmoothReLULayerDenseBatch ^
neural_networks\SoftmaxLayerDenseBatch ^
neural_networks\PReLULayerDenseBatch ^
neural_networks\TanhLayerDenseBatch ^
neural_networks\LRNLayerDenseBatch ^
neural_networks\Conv2DLayerDenseBatch ^
neural_networks\AvePool1DLayerDenseBatch ^
neural_networks\MaxPool1DLayerDenseBatch ^
neural_networks\AvePool2DLayerDenseBatch ^
neural_networks\MaxPool2DLayerDenseBatch ^
neural_networks\StochPool2DLayerDenseBatch ^
neural_networks\AvePool3DLayerDenseBatch ^
neural_networks\MaxPool3DLayerDenseBatch ^
neural_networks\LogisticLayerDenseBatch ^
neural_networks\ConcatLayerDenseBatch ^
neural_networks\LossSoftmaxEntrLayerDenseBatch ^
neural_networks\NeuralNetDenseBatch ^
neural_networks\NeuralNetPredicDenseBatch ^
neural_networks\Locallycon2DLayerDenseBatch ^
neural_networks\LCNLayerDenseBatch ^
neural_networks\SpatAvePool2DLayerDenseBatch ^
neural_networks\SpatMaxPool2DLayerDenseBatch ^
neural_networks\SpatStochPool2DLayerDenseBatch

