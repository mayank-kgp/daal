/* file: LossSoftmaxEntrLayerDenseBatch.java */
/*******************************************************************************
* Copyright 2014-2016 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
 //  Content:
 //     Java example of softmax cross-entropy layer in the batch processing mode
 ////////////////////////////////////////////////////////////////////////////////
 */

package com.intel.daal.examples.neural_networks;

import com.intel.daal.algorithms.neural_networks.layers.softmax_cross.*;
import com.intel.daal.algorithms.neural_networks.layers.ForwardResultId;
import com.intel.daal.algorithms.neural_networks.layers.ForwardResultLayerDataId;
import com.intel.daal.algorithms.neural_networks.layers.loss.LossForwardInputId;
import com.intel.daal.algorithms.neural_networks.layers.BackwardResultId;
import com.intel.daal.algorithms.neural_networks.layers.BackwardInputId;
import com.intel.daal.algorithms.neural_networks.layers.BackwardInputLayerDataId;
import com.intel.daal.data_management.data.Tensor;
import com.intel.daal.data_management.data.HomogenTensor;
import com.intel.daal.examples.utils.Service;
import com.intel.daal.services.DaalContext;

/**
 * <a name="DAAL-EXAMPLE-JAVA-LOSSSOFTMAXCROSSENTROPYLAYERBATCH">
 * @example LossSoftmaxEntrLayerDenseBatch.java
 */
class LossSoftmaxEntrLayerDenseBatch {
    private static final String datasetFileName = "../data/batch/softmax_cross_entropy_layer.csv";
    private static final String datasetGroundTruthFileName = "../data/batch/softmax_cross_entropy_layer_ground_truth.csv";
    private static DaalContext context = new DaalContext();

    public static void main(String[] args) throws java.io.FileNotFoundException, java.io.IOException {
        /* Read datasetFileName from a file and create a tensor to store forward input data */
        Tensor data = Service.readTensorFromCSV(context, datasetFileName);
        Tensor groundTruth = Service.readTensorFromCSV(context, datasetGroundTruthFileName);

        /* Create an algorithm to compute forward softmax cross-entropy layer results using default method */
        SoftmaxCrossForwardBatch forwardLayer = new SoftmaxCrossForwardBatch(context, Double.class, SoftmaxCrossMethod.defaultDense);

        /* Set input objects for the forward softmax cross-entropy layer */
        forwardLayer.input.set(LossForwardInputId.data, data);
        forwardLayer.input.set(LossForwardInputId.groundTruth, groundTruth);

        /* Compute forward softmax cross-entropy layer results */
        SoftmaxCrossForwardResult forwardResult = forwardLayer.compute();

        /* Print the results of the forward softmax cross-entropy layer */
        Service.printTensor("Forward softmax cross-entropy layer result (first 5 rows):", forwardResult.get(ForwardResultId.value), 5, 0);
        Service.printTensor("Softmax cross-Entropy layer probabilities estimations (first 5 rows):", forwardResult.get(SoftmaxCrossLayerDataId.auxProbabilities), 5, 0);

        /* Create an algorithm to compute backward softmax cross-entropy layer results using default method */
        SoftmaxCrossBackwardBatch backwardLayer = new SoftmaxCrossBackwardBatch(context, Double.class, SoftmaxCrossMethod.defaultDense);

        /* Set input objects for the backward softmax cross-entropy layer */
        backwardLayer.input.set(BackwardInputLayerDataId.inputFromForward, forwardResult.get(ForwardResultLayerDataId.resultForBackward));

        /* Compute backward softmax cross-entropy layer results */
        SoftmaxCrossBackwardResult backwardResult = backwardLayer.compute();

        /* Print the results of the backward softmax cross-entropy layer */
        Service.printTensor("Backward softmax cross-entropy layer result (first 5 rows):", backwardResult.get(BackwardResultId.gradient), 5, 0);

        context.dispose();
    }
}
