#include "stdafx.h"
#include "examples.h"

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <Model/Text/Range.h>
#include <Model/Document/Document.h>
#include <Model/Bookmarks/BookmarkCollection.h>
#include <Model/Bookmarks/Bookmark.h>

using namespace Aspose::Words;

void AccessBookmarks()
{
    std::cout << "AccessBookmarks example started." << std::endl;
    // ExStart:AccessBookmarks
    // The path to the documents directory.
    System::String dataDir = GetDataDir_WorkingWithBookmarks();

    System::SharedPtr<Document> doc = System::MakeObject<Document>(dataDir + u"Bookmarks.doc");

    // By index.
    System::SharedPtr<Bookmark> bookmark1 = doc->get_Range()->get_Bookmarks()->idx_get(0);

    // By name.
    System::SharedPtr<Bookmark> bookmark2 = doc->get_Range()->get_Bookmarks()->idx_get(u"Bookmark2");
    // ExEnd:AccessBookmarks
    std::cout << "Bookmark by index is" << bookmark1->get_Name().ToUtf8String()
              << " and bookmark by name is " << bookmark2->get_Name().ToUtf8String() << std::endl;
    std::cout << "AccessBookmarks example finished." << std::endl << std::endl;
}
