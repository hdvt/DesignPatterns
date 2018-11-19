#include "include/view.h"
#include <iostream>

int main()
{
    CompositeView viewManager;
    \
    CompositeView* layer1 = new CompositeView();
    layer1->Add(new LeafView("Video 1", "../test.mp4"));
    layer1->Add(new LeafView("Video 2", "../test.mp4"));
    viewManager.Add(layer1);

    CompositeView* layer2 = new CompositeView();
    layer2->Add(new LeafView("Video 3", "../test.mp4"));
    layer2->Add(new LeafView("Video 4", "../test.mp4"));
    viewManager.Add(layer2);

    viewManager.SetBox(cv::Rect(0, 0, 1920, 1080));

    while (true)
    {
        viewManager.Display();
        if (cv::waitKey(5) == 27)
            break;
    }

    return 0;
}
