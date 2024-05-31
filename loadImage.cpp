#include "itkImage.h"
#include "itkImageFileReader.h"
#include "jlcxx/jlcxx.hpp"

using ImageType = itk::Image<unsigned char, 2>;

ImageType::Pointer loadImage(std::string filename) {
    auto reader = itk::ImageFileReader<ImageType>::New();
    reader->SetFileName(filename);
    reader->Update();
    return reader->GetOutput();
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod) {
    mod.method("loadImage", &loadImage);
}
