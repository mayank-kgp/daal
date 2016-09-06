/* file: pca_dense_svd_batch_kernel.h */
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
//  Declaration of template structs that calculate PCA SVD.
//--
*/

#ifndef __PCA_DENSE_SVD_BATCH_KERNEL_H__
#define __PCA_DENSE_SVD_BATCH_KERNEL_H__

#include "pca_batch.h"
#include "pca_types.h"
#include "svd/svd_dense_default_kernel.h"

#include "pca_dense_svd_base.h"

namespace daal
{
namespace algorithms
{
namespace pca
{
namespace internal
{

template <typename interm, CpuType cpu>
class PCASVDBatchKernel : public PCASVDKernelBase<interm, cpu>
{
public:
    PCASVDBatchKernel() {};

    void compute(const data_management::NumericTablePtr &data,
                 data_management::NumericTablePtr &eigenvalues,
                 data_management::NumericTablePtr &eigenvectors);

    ~PCASVDBatchKernel() {}

protected:
    void normalizeDataset();

    void decompose();

    data_management::NumericTablePtr _data;
    data_management::NumericTablePtr _eigenvalues;
    data_management::NumericTablePtr _eigenvectors;

    size_t _nObservations;
    size_t _nFeatures;

    data_management::NumericTablePtr _normalizedData;
};

} // namespace internal
} // namespace pca
} // namespace algorithms
} // namespace daal
#endif
