/* file: softmax_cross_layer_backward_types.h */
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
//++
//  Implementation of the backward softmax cross-entropy layer types.
//--
*/

#ifndef __NEURAL_NENTWORK_LOSS_SOFTMAX_CROSS_LAYER_BACKWARD_TYPES_H__
#define __NEURAL_NENTWORK_LOSS_SOFTMAX_CROSS_LAYER_BACKWARD_TYPES_H__

#include "algorithms/algorithm.h"
#include "data_management/data/tensor.h"
#include "data_management/data/homogen_tensor.h"
#include "services/daal_defines.h"
#include "algorithms/neural_networks/layers/layer_backward_types.h"
#include "algorithms/neural_networks/layers/loss/loss_layer_backward_types.h"
#include "algorithms/neural_networks/layers/loss/softmax_cross_layer_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace loss
{
namespace softmax_cross
{
/**
 * @defgroup softmax_cross_backward Backward Softmax Cross-entropy Layer
 * \copydoc daal::algorithms::neural_networks::layers::loss::softmax_cross::backward
 * @ingroup softmax_cross
 * @{
 */
/**
 * \brief Contains classes for the backward softmax cross-entropy layer
 */
namespace backward
{
/**
 * \brief Contains version 1.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface1
{
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOSS__SOFTMAX_CROSS__BACKWARD__INPUT"></a>
 * \brief %Input objects for the backward softmax cross-entropy layer
 */
class Input : public loss::backward::Input
{
public:
    /** Default constructor */
    Input() {};

    virtual ~Input() {}

    /**
     * Returns an input object for the backward softmax cross-entropy layer
     */
    using loss::backward::Input::get;

    /**
     * Sets an input object for the backward softmax cross-entropy layer
     */
    using loss::backward::Input::set;

    /**
     * Returns an input object for the backward softmax cross-entropy layer
     * \param[in] id    Identifier of the input object
     * \return          %Input object that corresponds to the given identifier
     */
    services::SharedPtr<data_management::Tensor> get(LayerDataId id) const
    {
        services::SharedPtr<layers::LayerData> layerData =
            services::staticPointerCast<layers::LayerData, data_management::SerializationIface>(Argument::get(layers::backward::inputFromForward));
        return services::staticPointerCast<data_management::Tensor, data_management::SerializationIface>((*layerData)[id]);
    }

    /**
     * Sets an input object for the backward softmax cross-entropy layer
     * \param[in] id      Identifier of the input object
     * \param[in] value   Pointer to the object
     */
    void set(LayerDataId id, const services::SharedPtr<data_management::Tensor> &value)
    {
        services::SharedPtr<layers::LayerData> layerData =
            services::staticPointerCast<layers::LayerData, data_management::SerializationIface>(Argument::get(layers::backward::inputFromForward));
        (*layerData)[id] = value;
    }

    /**
     * Checks an input object for the backward softmax cross-entropy layer
     * \param[in] par     Algorithm parameter
     * \param[in] method  Computation method
     */
    void check(const daal::algorithms::Parameter *par, int method) const DAAL_C11_OVERRIDE
    {
        loss::backward::Input::check(par, method);
        if (!data_management::checkTensor(get(auxProbabilities).get(), this->_errors.get(), auxProbabilitiesStr())) { return; }
        if (!data_management::checkTensor(get(auxGroundTruth).get(), this->_errors.get(), auxGroundTruthStr())) { return; }
    }
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOSS__SOFTMAX_CROSS__BACKWARD__RESULT"></a>
 * \brief Provides methods to access the result obtained with the compute() method
 *        of the backward softmax cross-entropy layer
 */
class Result : public loss::backward::Result
{
public:
    /** Default constructor */
    Result() : loss::backward::Result() {};

    virtual ~Result() {};

    /**
     * Returns an result object for the backward softmax cross-entropy layer
     */
    using loss::backward::Result::get;

    /**
     * Sets an result object for the backward softmax cross-entropy layer
     */
    using loss::backward::Result::set;

    /**
     * Checks the result of the backward softmax cross-entropy layer
     * \param[in] input   %Input object for the layer
     * \param[in] par     %Parameter of the layer
     * \param[in] method  Computation method
     */
    void check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, int method) const DAAL_C11_OVERRIDE
    {}

    /**
     * Allocates memory to store the result of the backward softmax cross-entropy layer
     * \param[in] input Pointer to an object containing the input data
     * \param[in] method Computation method for the layer
     * \param[in] parameter %Parameter of the backward softmax cross-entropy layer
     */
    template <typename algorithmFPType>
    void allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method)
    {
        if (!get(layers::backward::gradient))
        {
            const Input *in = static_cast<const Input *>(input);

            services::SharedPtr<data_management::Tensor> probabilitiesTable = in->get(auxProbabilities);

            if(probabilitiesTable == 0) { this->_errors->add(services::ErrorNullInputNumericTable); return; }

            DAAL_ALLOCATE_TENSOR_AND_SET(layers::backward::gradient, probabilitiesTable->getDimensions());
        }
    }

    /**
    * Returns the serialization tag of the backward softmax cross-entropy layer result
    * \return         Serialization tag of the backward softmax cross-entropy layer result
    */
    int getSerializationTag() DAAL_C11_OVERRIDE  { return SERIALIZATION_NEURAL_NETWORKS_LAYERS_LOSS_SOFTMAX_CROSS_BACKWARD_RESULT_ID; }

    /**
    *  Serializes the object
    *  \param[in]  arch  Storage for the serialized object or data structure
    */
    void serializeImpl(data_management::InputDataArchive  *arch) DAAL_C11_OVERRIDE
    {serialImpl<data_management::InputDataArchive, false>(arch);}

    /**
    *  Deserializes the object
    *  \param[in]  arch  Storage for the deserialized object or data structure
    */
    void deserializeImpl(data_management::OutputDataArchive *arch) DAAL_C11_OVERRIDE
    {serialImpl<data_management::OutputDataArchive, true>(arch);}

protected:
    /** \private */
    template<typename Archive, bool onDeserialize>
    void serialImpl(Archive *arch)
    {
        daal::algorithms::Result::serialImpl<Archive, onDeserialize>(arch);
    }
};
} // namespace interface1
using interface1::Input;
using interface1::Result;
} // namespace backward
/** @} */
} // namespace softmax_cross
} // namespace loss
} // namespace layers
} // namespace neural_networks
} // namespace algorithm
} // namespace daal
#endif
