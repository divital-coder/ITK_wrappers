#include "itkImage.h"
#include "itkImageFileReader.h"

using ImageType = itk::Image<unsigned char, 2>;

ImageType::Pointer loadImage(std::string filename) {
    auto reader = itk::ImageFileReader<ImageType>::New();
    reader->SetFileName(filename);
    reader->Update();
    return reader->GetOutput();
}
