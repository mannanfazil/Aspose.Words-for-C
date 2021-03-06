#include "stdafx.h"
#include "examples.h"

#include <system/enumerator_adapter.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/date_time.h>
#include <system/collections/ienumerator.h>
#include <Model/Properties/DocumentProperty.h>
#include <Model/Properties/CustomDocumentProperties.h>
#include <Model/Properties/BuiltInDocumentProperties.h>
#include <Model/Document/Document.h>
#include <cstdint>


using namespace Aspose::Words;
using namespace Aspose::Words::Properties;

namespace
{
    void EnumerateProperties(const System::String& dataDir)
    {
        // ExStart:EnumerateProperties
        System::String fileName = dataDir + u"Properties.doc";
        System::SharedPtr<Document> doc = System::MakeObject<Document>(fileName);
        std::cout << "1. Document name: " << fileName.ToUtf8String() << std::endl;

        std::cout << "2. Built-in Properties" << std::endl;
        for (System::SharedPtr<DocumentProperty> prop : System::IterateOver(doc->get_BuiltInDocumentProperties()))
        {
            std::cout << prop->get_Name().ToUtf8String() << " : " << prop->get_Value()->ToString().ToUtf8String() << std::endl;
        }

        std::cout << "3. Custom Properties" << std::endl;
        for (System::SharedPtr<DocumentProperty> prop : System::IterateOver(doc->get_CustomDocumentProperties()))
        {
            std::cout << prop->get_Name().ToUtf8String() << " : " << prop->get_Value()->ToString().ToUtf8String() << std::endl;
        }
        // ExEnd:EnumerateProperties
    }

    void CustomAdd(const System::String& dataDir)
    {
        // ExStart:CustomAdd
        System::SharedPtr<Document> doc = System::MakeObject<Document>(dataDir + u"Properties.doc");
        System::SharedPtr<CustomDocumentProperties> props = doc->get_CustomDocumentProperties();
        if (props->idx_get(u"Authorized") == nullptr)
        {
            props->Add(u"Authorized", true);
            props->Add(u"Authorized By", System::String(u"John Smith"));
            props->Add(u"Authorized Date", System::DateTime::get_Today());
            props->Add(u"Authorized Revision", doc->get_BuiltInDocumentProperties()->get_RevisionNumber());
            props->Add(u"Authorized Amount", 123.45);
        }
        // ExEnd:CustomAdd
    }

    void CustomRemove(const System::String& dataDir)
    {
        // ExStart:CustomRemove
        System::SharedPtr<Document> doc = System::MakeObject<Document>(dataDir + u"Properties.doc");
        doc->get_CustomDocumentProperties()->Remove(u"Authorized Date");
        // ExEnd:CustomRemove
    }

    void RemovePersonalInformation(const System::String &dataDir)
    {
        // ExStart:RemovePersonalInformation
        System::SharedPtr<Document> doc = System::MakeObject<Document>(dataDir + u"Properties.doc");
        doc->set_RemovePersonalInformation(true);
        System::String outputPath = dataDir + GetOutputFilePath(u"DocProperties.RemovePersonalInformation.docx");
        doc->Save(outputPath);
        // ExEnd:RemovePersonalInformation
        std::cout << "Personal information has removed from document successfully." << std::endl << "File saved at " << outputPath.ToUtf8String() << std::endl;
    }
}

void DocProperties()
{
    std::cout << "DocProperties example started." << std::endl;
    // The path to the documents directory.
    System::String dataDir = GetDataDir_WorkingWithDocument();
    // Enumerates through all built-in and custom properties in a document.
    EnumerateProperties(dataDir);
    // Checks if a custom property with a given name exists in a document and adds few more custom document properties.
    CustomAdd(dataDir);
    // Removes a custom document property.
    CustomRemove(dataDir);
    RemovePersonalInformation(dataDir);
    std::cout << "DocProperties example finished." << std::endl << std::endl;
}
