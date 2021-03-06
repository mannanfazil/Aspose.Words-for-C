#include "stdafx.h"
#include "examples.h"

#include <system/shared_ptr.h>

#include "Model/Document/Document.h"
#include <Model/Sections/Section.h>
#include <Model/Sections/SectionCollection.h>
#include <Model/Text/Range.h>

using namespace Aspose::Words;

void RangesDeleteText()
{
    std::cout << "RangesDeleteText example started." << std::endl;
    // ExStart:RangesDeleteText
    // The path to the documents directory.
    System::String dataDir = GetDataDir_WorkingWithRanges();
    auto doc = System::MakeObject<Document>(dataDir + u"Document.doc");
    doc->get_Sections()->idx_get(0)->get_Range()->Delete();
    // ExEnd:RangesDeleteText
    std::cout << "All characters of a range deleted successfully." << std::endl;
    std::cout << "RangesDeleteText example finished." << std::endl << std::endl;
}